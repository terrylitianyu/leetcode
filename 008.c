/**
 * @file 008.c
 */

 #include <stdio.h>
 #include <stdlib.h>


int myAtoi(char* str)
{
  if (!str) return 0;
  int len = strlen(str);
  if (len == 0) return 0;
  int rtn = 0;
  int flag = 0;
  int blank_flag = 0;
  int bound_flag = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == ' ' && blank_flag == 0)
    {
      continue;
    }
    if (str[i] == '+' && flag == 0)
    {
      flag = 1;
      blank_flag = 1;
      continue;
    }
    if (str[i] == '-' && flag == 0)
    {
      flag = -1;
      blank_flag = 1;
      continue;
    }
    if (str[i] >= '0' && str[i] <= '9')
    {
      blank_flag = 1;
      if(flag == -1)
      {
        if (rtn > 214748364 || (rtn == 214748364 && str[i] > '8'))
          return INT_MIN;
      }
      else
      {
        if (rtn > 214748364 || (rtn == 214748364 && str[i] > '7'))
          return INT_MAX;
      }
      rtn = rtn * 10 + (int)str[i] - 48;
    }
    else break;
  }
  if (flag == 0) flag = 1;
  return flag * rtn;
}
