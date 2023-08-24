/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){

  if (head == NULL || head->next == NULL) return head;

  struct ListNode* prev = head;
  
  struct ListNode* curr = prev->next;

  head->next = NULL;

  while (prev != NULL && curr != NULL)
  {
    struct ListNode* next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
  }

  return prev;
}

