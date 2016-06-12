/**
 * @file 014.c
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

char* longestCommonPrefix(char** strs, int strsSize) {
  if (!strs) return NULL;
  char* rtn = malloc(sizeof(char) * MAX_LENGTH);
  rtn[0] = '\0';
  if (strsSize == 0) return rtn;
  if (strsSize == 1)
  {
    strcpy(rtn, strs[0]);
    return rtn;
  }
  int index = 0;
  int flag = 0;
  while(1)
  {
    for(int i = 0; i < strsSize - 1; i++)
    {
      if (strs[i][index] != strs[i+1][index])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
    {
      rtn[index] = '\0';
      break;
    }
    rtn[index] = strs[0][index];
    index++;
  }
  return rtn;
}
