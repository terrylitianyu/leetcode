/**
 * @file 021.c
 *
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
