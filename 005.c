/**
 * @file 005.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* s, int start, int end, int len, int** ht);

char* longestPalindrome(char* s) {
  if(!s) return NULL;
  if(strlen(s) == 0) return s;

  int len = strlen(s);
  int* ht = malloc(sizeof(int) * len * (len+1));
  int i,j;
  for (i = 0; i < len; i++)
  {
    for (j = 0; j <= len; j++)
    {
      ht[i*len+j] = -1;;
    }
  }
  int start_index = 0;
  int end_index = len;
  int max_len = 0;
  for(i = 0; i < len; i++)
  {
    for(j = i; j <= len; j++)
    {
      if(is_palindrome(s, i, j, len, &ht))
      {
        if (j - i > max_len)
        {
          max_len = j - i;
          start_index = i;
          end_index = j;
        }
      }
    }
  }
  // char* rtn = malloc(sizeof(char)*(max_len+1));
  // memcpy(rtn, s + start_index, end_index - start_index);
  // rtn[max_len] = '\0';
  // return rtn;
  s[end_index] = '\0';
  return s+start_index;
}

int is_palindrome(char* s, int start, int end, int len, int** ht)
{
  if (start > end)
  {
    (*ht)[start*len+end] = 0;
    return 0;
  }
  if ((*ht)[start*len+end] >= 0) return (*ht)[start*len+end];
  if (start == end || start == end - 1) (*ht)[start*len+end] = 1;
  else (*ht)[start*len+end] = (s[start] == s[end - 1] &&
                               is_palindrome(s, start+1, end-1, len, ht));

  return (*ht)[start*len+end];
}

int main(int argc, char** argv) {
  char* s = "dddffddffddd";
  // int len = strlen(s);
  // int* ht = malloc(sizeof(int) * len * (len+1));
  // int i,j;
  // for (i = 0; i < len; i++)
  // {
  //   for (j = 0; j < len; j++)
  //   {
  //     ht[i*len+j] = -1;
  //   }
  // }


  // for (i = 0; i < len; i++)
  // {
  //   for (j = 0; j <= len; j++)
  //   {
  //     is_palindrome(s, i, j, len, &ht);
  //   }
  //   printf("\n");
  // }

  // for (i = 0; i < len; i++)
  // {
  //   for (j = 0; j <= len; j++)
  //   {
  //     printf("%d,",ht[i*len+j]);
  //   }
  //   printf("\n");
  // }
  // return 0;
  char* result = longestPalindrome(s);
  printf("%s\n", result);
  return 0;
}
