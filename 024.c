/**
 * @file 024.c
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
  if (head == NULL) return NULL;
  if (head->next == NULL)  return head;
  struct ListNode* rtn = head->next;

  struct ListNode* prenode = head;
  struct ListNode* currnode = head->next;
  while(prenode && currnode)
  {
    struct ListNode* tempnode = currnode->next;
    currnode->next = prenode;
    prenode->next = tempnode;
    if (tempnode == NULL)
    {
      break;
    }
    if (tempnode->next != NULL)
      prenode->next = tempnode->next;
    prenode = tempnode;
    currnode = tempnode->next;
  }
  return rtn;
}
