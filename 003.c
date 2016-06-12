#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
typedef struct char_hash_t {
  int prev;
} char_hash;
*/

int lengthOfLongestSubstring(char* s) {
  int max = 0;
  int count = 0;
  int first = 0;
  int len = strlen(s);
  int begin = -1;
  int ch_prev[256];
  char char_id;
  int i = 0;
  for (; i < 256; i++)
  {
    ch_prev[i] = -1;
  }
  for(i = 0; i < len; i++)
  {
    char_id = s[i];
    count++;
    if (ch_prev[char_id] == -1)
    {
      ch_prev[char_id] = i;
    }
    else
    {
      if (ch_prev[char_id] >= first)
      {
        count = i - ch_prev[char_id];
        first = ch_prev[char_id] + 1;
      }
      ch_prev[char_id] = i;
    }
    if (count > max)
    {
      max = count;
      begin = first;
    }
  }
  return max;
}


int main(int argc, char** argv)
{
  char s[100] = "abcabcdefbb";
  int rtn = lengthOfLongestSubstring(s);
  printf("%d\n", rtn);
  return 0;
}
