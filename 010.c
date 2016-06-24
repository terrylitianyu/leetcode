/**
 * @file 010.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int is_match_help(char* s, int si, int sl, char*p, int pi, int pl, int** ht);


bool isMatch(char* s, char* p) {
  if (!s || !p) return false;
  int sl = strlen(s);
  int pl = strlen(p);
  int* ht = calloc((sl+1)*(pl+1), sizeof(int));
  for (int i = 0; i < (sl+1)*(pl+1); i++)
  {
    ht[i] = -1;
  }
  return (bool)is_match_help(s, 0, sl, p, 0, pl, &ht);
}


int is_match_help(char* s, int si, int sl, char*p, int pi, int pl, int** ht) {
  //@ASSERT si <= sl && pi <= pl

  if (pi == pl && si == sl) return 1;
  if ((pi == pl && si < sl) || (si == sl && (pi == pl - 1 || p[pi + 1] != '*')))
    return 0;
  if ((*ht)[pi*sl+si] >= 0) return (*ht)[pi*sl+si];
  else
  {
    if (pi == pl - 1 || p[pi + 1] != '*')
    {
      if (p[pi] == '.')
        (*ht)[pi*sl+si] = is_match_help(s, si+1, sl, p, pi+1, pl, ht);
      else
        (*ht)[pi*sl+si] = (s[si] == p[pi] &&
                             is_match_help(s, si+1, sl, p, pi+1, pl, ht));
    }
    else
    {
      if ((p[pi] == '.' || s[si] == p[pi]) && si != sl)
        (*ht)[pi*sl+si] = (is_match_help(s, si+1, sl, p, pi, pl, ht) ||
                         is_match_help(s, si, sl, p, pi+2, pl, ht));
      else
        (*ht)[pi*sl+si] = (is_match_help(s, si, sl, p, pi+2, pl, ht));
    }
    return (*ht)[pi*sl+si];
  }
}

int main(int argc, char** argv)
{
  char* s = "";
  char* p = ".*";
  bool result = isMatch(s, p);
  int rtn = (int) result;
  printf("result:%d\n", rtn);
  return 0;
}
