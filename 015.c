#include <stdio.h>
#include <stdlib.h>
#define HT_SIZE 1024

typedef struct l_list_t {
  int index;
  int val;
  struct l_list_t* next;
} l_list;

int compare(const void* a, const void* b);

int* twoSum(int* nums, int numsSize, int target, int start,
            int least, l_list** ht);



int** threeSum(int* nums, int numsSize, int* returnSize)
{
  if(numsSize < 3) return NULL;
  int malloc_size = numsSize * (numsSize - 1) * (numsSize - 2) / 6;
  l_list** ht = calloc(HT_SIZE, sizeof(l_list*));
  int** rtn = malloc((*returnSize) * sizeof(int*));
  int i = 0;
  int j = 0;
  int start = 0;
  int least = 0;
  int rtn_index = 0;
  int* search_rslt;
  int temp = 0;
  qsort(nums, numsSize, sizeof(int), compare);
  for (; i < numsSize; i++)
  {
    l_list* entry = malloc(sizeof(l_list));
    entry->index = i;
    entry->val = nums[i];
    temp = nums[i] % HT_SIZE;
    if (temp < 0) {temp = -temp;}
    entry->next = ht[temp];
    ht[temp] = entry;
  }
  i = 0;
  for (; i < numsSize; i++)
  {
    int flag = 0;
    j = 0;
    for (; j < malloc_size; j++)
    {
      if (rtn[j] == NULL) break;
      if (rtn[j][0] == nums[i])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    start = i + 1;
    least = nums[i];
    do {
      search_rslt = twoSum(nums, numsSize, -nums[i], start, least, ht);
      start = search_rslt[0] + 1;
      least = nums[search_rslt[0]] + 1;
      if (start != 0)
      {
        int* rtn_entry = malloc(3 * sizeof(int));
        rtn_entry[0] = nums[i];
        rtn_entry[1] = nums[search_rslt[0]];
        rtn_entry[2] = nums[search_rslt[1]];
        rtn[rtn_index] = rtn_entry;
        rtn_index++;
      }
    } while (start != 0);
  }
  *returnSize = rtn_index;
  return rtn;
}

int compare (const void* a, const void* b)
{
  return ( *(int*)a - *(int*)b );
}

int* twoSum(int* nums, int numsSize, int target, int start,
            int least, l_list** ht)
{
  int* rtn = malloc(2 * sizeof(int));
  int i = start;
  int temp = 0;
  int left = 0;
  int left_id;
  int index1 = -1;
  int index2 = -1;
  l_list* ll_temp = NULL;

  for (;i < numsSize;i++)
  {
    if (nums[i] < least) continue;
    index1 = i;
    temp = nums[i];
    left = target - temp;
    left_id = left % HT_SIZE;
    if (left_id < 0) {left_id = -left_id;}
    ll_temp = ht[left_id];
    while (ll_temp != NULL)
    {
      if (ll_temp->val == left && ll_temp->index > i)
      {
        index2 = ll_temp->index;
        break;
      }
      ll_temp = ll_temp->next;
    }
    if (index2 != -1) break;
  }
  if (index2 == -1) {index1 = -1;}
  rtn[0] = index1;
  rtn[1] = index2;
  return rtn;
}

int main(int argc, char** argv)
{
  int test_num[4] = {0, 0, 0, 0};
  int rtn_size = 8;
  int** rtn = threeSum(test_num, 4, &rtn_size);
  int i = 0;
  if (rtn == NULL)
  {
    printf("No solution!");
    return 0;
  }
  for (; i < 8; i++)
  {
    if (rtn[i] == NULL) break;
    printf("%d, %d, %d\n", rtn[i][0], rtn[i][1], rtn[i][2]);
  }
  //qsort(test_num, 6, sizeof(int), compare);
  //printf(" %d\n", test_num[0]);
  /* Should free the malloced things */
  // free(rtn);
  return 0;
}
