ListNode *deleteDuplicates(ListNode *head) {
  if (!head) return head;
  ListNode *p = head;
  for (ListNode *i = p->next; i; i = i->next) {
    p->next = NULL;
    if (i->val != p->val) {
      p->next = i;
      p = i;
    }
  }
  p->next = NULL;
  return head;
}
