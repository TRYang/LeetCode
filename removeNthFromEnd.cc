ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head) return NULL;
  ListNode *ptr = head;
  for (int i = 0; i < n; i++) ptr = ptr->next;
  if (!ptr) return head->next;
  ListNode *cur = head;
  while (true) {
    ptr = ptr->next;
    if (!ptr) {
      cur->next = cur->next->next;
      return head;
    }
    cur = cur->next;
  }
}
