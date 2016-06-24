/**
 * @file 025.c
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKgroupHelp(struct ListNode* head, int k) {
  if(k == 0) return NULL;
  if(k == 1) return head;
  struct ListNode* reversed = reverseKgroupHelp(head->next, k - 1);
  reversed->next = head;
  return head;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
  struct ListNode* rtn = head;
  struct ListNode* temp = head;
  int i = 0;
  for(i = 0; i < k; i++)
  {
    if(!temp) break;
    if (i < k - 1) temp = temp->next;
  }
  if (i < k) return rtn;
  rtn = temp;
  struct ListNode* new_head = temp->next;
  struct ListNode* tail = reverseKgroupHelp(head, k);
  tail->next = reverseKGroup(new_head, k);
  return rtn;

}
