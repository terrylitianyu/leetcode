/**
 * @file 023.c
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    struct ListNode* rtn = malloc(sizeof(struct ListNode));
    struct ListNode* prenode = rtn;
    while (l1 != NULL && l2 != NULL)
    {
      struct ListNode* temp = malloc(sizeof(struct ListNode));
      if (l1->val < l2->val)
      {
        temp->val = l1->val;
        l1 = l1->next;
      }
      else
      {
        temp->val = l2->val;
        l2 = l2->next;
      }
      prenode->next = temp;
      prenode = temp;
    }
    if (l1 == NULL) prenode->next = l2;
    if (l2 == NULL) prenode->next = l1;

    return rtn->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
  if (listsSize <= 0) return NULL;
  if (listsSize == 1) return lists[0];
  else
  {
    return mergeTwoLists(mergeKLists(lists, listsSize / 2),
                         mergeKLists(lists + listsSize / 2,
                                     listsSize - listsSize / 2));
  }
}




// struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
// {
//   struct ListNode* rtn = malloc(sizeof(struct ListNode));
//   struct ListNode* pre_node = rtn;
//   int null_num = 0;
//   int min = 0x7FFFFFFF;
//   int min_index = -1;
//   while (null_num < listsSize)
//   {
//     null_num = 0;
//     min = 0x7FFFFFFF;
//     min_index = -1;
//     struct ListNode* temp = malloc(sizeof(struct ListNode));
//     for (int i = 0; i < listsSize; i++)
//     {
//       if(lists[i] == NULL)
//       {
//         null_num++;
//         continue;
//       }
//       if(lists[i]->val < min)
//       {
//         min = lists[i]->val;
//         min_index = i;
//       }
//     }
//     if (min_index != -1)
//     {
//       temp->val = min;
//       lists[min_index] = lists[min_index]->next;
//       pre_node->next = temp;
//       pre_node = temp;
//     }
//   }
//   return rtn->next;
// }
