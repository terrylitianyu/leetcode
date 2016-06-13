/**
 * @file 022.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void generateNewParenthesis(char** rtn, char* prefix,
  int left, int right, int len, int* count){
  if (right == 0)
  {
    rtn[*count] = prefix;
    (*count)++;
    return;
  }
  if (left == 0)
  {
    strncat(prefix, ")", len);
    generateNewParenthesis(rtn, prefix, left, right-1, len, count);
  }
  else
  {
    if (left >= right)
    {
      char* left_s = malloc(sizeof(char) * (len+1));
      strcpy(left_s, prefix);
      strncat(left_s, "(", len);
      generateNewParenthesis(rtn, left_s, left-1, right, len, count);
    }
    else
    {
      char* left_s = malloc(sizeof(char) * (len+1));
      char* right_s = malloc(sizeof(char) * (len+1));
      strcpy(left_s, prefix);
      strcpy(right_s, prefix);
      strncat(left_s, "(", len);
      strncat(right_s, ")", len);
      generateNewParenthesis(rtn, left_s, left-1, right, len, count);
      generateNewParenthesis(rtn, right_s, left, right-1, len, count);
    }
  }
}

int counter(int left, int right)
{
  if (left == 0) return 1;
  else
  {
    if (left >= right)
    {
      return counter(left - 1, right);
    }
    else
    {
      return counter(left - 1, right) + counter(left, right - 1);
    }
  }
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
  *returnSize = counter(n, n);
  char** rtn = malloc(sizeof(char*) * (*returnSize));
  int* count;
  *count = 0;
  generateNewParenthesis(rtn, "", n, n, 2*n, count);
  return rtn;
}

int main(int argc, char** argv)
{
  int a = 3;
  int result;
  generateParenthesis(a, &result);
  printf("%d\n", result);
  return 0;
}
