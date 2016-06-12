#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
  int len = strlen(s);
  char* rtn = malloc(sizeof(char) * (len + 1));
  if (numRows == 1)
  {
    strcpy(rtn, s);
    return rtn;
  }
  int i = 0;
  int j = 0;
  int t = 0;
  int c = (len - 1) / (2* numRows - 2) + 1;
  int p = 0;
  while (i < c)
  {
    rtn[i] = s[i * 2 * (numRows - 1)];
    i++;
  }
  i = c;
  for (j = 0; j < numRows - 2; j++)
  {
    p = j + 1;
    t = 0;
    while (p < len && i < len)
    {
      rtn[i] = s[p];
      printf("char:%c, j:%d, i:%d, p:%d\n", s[p], j, i, p);
      if (t % 2 == 0)
      {
        p += 2 * (numRows - 2 - j);
      }
      else
      {
        p += 2 * (j + 1);
      }
      i++;
      t++;
    }
  }
  j = 0;
  while (i < len)
  {
    rtn[i] = s[j * 2 * (numRows - 1) + numRows - 1];
    j++;
    i++;
  }
  rtn[i] = '\0';
  return rtn;
}

int main(int argc, char** argv)
{
  char test[15] = "PAHNAPLSIIGYIR";
  char* rtn = convert(test, 5);
  int k = -7 % 3;
  printf("%d\n", k);
  printf("%s\n", rtn);
  return 0;
}
