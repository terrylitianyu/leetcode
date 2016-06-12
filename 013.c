/**
 * @file 013.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanchar_to_int (char c)
{
  switch(c)
  {
    case 'I':
      return 1;
      break;
    case 'V':
      return 5;
      break;
    case 'X':
      return 10;
      break;
    case 'L':
      return 50;
      break;
    case 'C':
      return 100;
      break;
    case 'D':
      return 500;
      break;
    case 'M':
      return 1000;
      break;
    default:
      return 0;
      break;
  }
}


int romanToInt(char* s) {
  if (!s) return -1;
  int len = strlen(s);
  int rtn = 0;
  int temp = 0;
  for (int index = 0; index < len; index++)
  {
    temp = romanchar_to_int(s[index]);
    if(index == len - 1)
    {
      rtn += temp;
    }
    else
    {
      if(temp < romanchar_to_int(s[index + 1])) rtn -= temp;
      else rtn+= temp;
    }
  }
  return rtn;
}
