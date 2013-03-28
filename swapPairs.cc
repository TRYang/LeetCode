ListNode *swapPairs(ListNode *head) {
  if (!head) return NULL;
  if (!head->next) return head;
  ListNode *p = head, *q = p->next;
  head = head->next;
  while (q) {
    p->next = q->next;
    q->next = p;
    ListNode *tp = p;
    p = p->next;
    if (!p) q = NULL; else q = p->next;
    if (p && q) tp->next = q;
  }
  return head;
}
