/** @file 002.c
 *
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
  int val;
  struct ListNode* next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  if(l1 == NULL || l2 == NULL)
  {
    return;
  }
  int flag = 0;
  struct ListNode* rtn = malloc(sizeof(struct ListNode));
  rtn->val = 0;
  rtn->next = NULL;
  struct ListNode* prev = rtn;
  struct ListNode* l1_bit = l1;
  struct ListNode* l2_bit = l2;
  int l1_val = 0;
  int l2_val = 0;
  while (1)
  {
    if (l1_bit == NULL)
    {
      l1_val = 0;
    }
    else
    {
      l1_val = l1_bit->val;
      l1_bit = l1_bit->next;
    }
    if (l2_bit == NULL)
    {
      l2_val = 0;
    }
    else
    {
      l2_val = l2_bit->val;
      l2_bit = l2_bit->next;
    }

    prev->val = (l1_val + l2_val + flag) % 10;
    printf("in running: %d\n", prev->val);
    flag = (l1_val + l2_val + flag) / 10;
    if (l1_bit == NULL && l2_bit == NULL && flag == 0)
    {
      break;
    }
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->next = NULL;
    temp->val = 0;
    prev->next = temp;
    prev = temp;
  }
  return rtn;
}

int main(int argc, char** argv)
{
  struct ListNode* a0 = malloc(sizeof(struct ListNode));
  struct ListNode* a1 = malloc(sizeof(struct ListNode));
  struct ListNode* a2 = malloc(sizeof(struct ListNode));
  struct ListNode* b0 = malloc(sizeof(struct ListNode));
  struct ListNode* b1 = malloc(sizeof(struct ListNode));
  struct ListNode* b2 = malloc(sizeof(struct ListNode));

  a0->val = 2;
  a1->val = 4;
  a2->val = 3;

  b0->val = 5;
  b1->val = 6;
  b2->val = 4;

  a0->next = a1;
  a1->next = a2;
  a2->next = NULL;

  b0->next = b1;
  b1->next = b2;
  b2->next = NULL;

  struct ListNode* rtn = addTwoNumbers(a0, b0);
  struct ListNode* temp = rtn;
  while (temp != NULL)
  {
    printf("%d\n", temp->val);
    temp = temp->next;
  }
  return 0;
}
