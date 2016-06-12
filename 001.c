#include <stdio.h>
#include <stdlib.h>
#define HT_SIZE 1024

typedef struct l_list_t {
  int index;
  int val;
  struct l_list_t* next;
} l_list;



int* twoSum(int* nums, int numsSize, int target)
{
  l_list** ht = calloc(HT_SIZE, sizeof(l_list*));
  int* rtn = malloc(2 * sizeof(int));
  int i = 0;
  int temp = 0;
  int left = 0;
  int left_id;
  int index1 = 0;
  int index2 = 0;
  l_list* ll_temp = NULL;

  for (;i < numsSize;i++)
  {
    l_list* entry = malloc(sizeof(l_list));
    entry->index = i + 1;
    entry->val = nums[i];
    temp = nums[i] % HT_SIZE;
    if (temp < 0) {temp = -temp;}
    entry->next = ht[temp];
    ht[temp] = entry;
  }
  i = 0;

  for (;i < numsSize;i++)
  {
    index1 = i + 1;
    temp = nums[i];
    left = target - temp;
    left_id = left % HT_SIZE;
    if (left_id < 0) {left_id = -left_id;}
    ll_temp = ht[left_id];
    while (ll_temp != NULL)
    {
      if (ll_temp->val == left && ll_temp->index != i + 1)
      {
        index2 = ll_temp->index;
        break;
      }
      ll_temp = ll_temp->next;
    }
    if (index2 != 0) break;
  }
  if (index2 == 0) {index1 = 0;}
  rtn[0] = index1;
  rtn[1] = index2;
  return rtn;
}




int main(int argc, char** argv)
{
  int test_num[4] = {2, 7, 11, 19};
  int *rtn = twoSum(test_num, 4, 9);
  printf("%d, %d\n", rtn[0], rtn[1]);
  int i = (-9) / 4;
  printf("%d\n", i);
  /* Should free the malloced things */
  // free(rtn);
  return 0;
}
