ListNode *rotateRight(ListNode *head, int k) {
  if (!head) return NULL;
  ListNode *super_head = new ListNode(-1);
  super_head->next = head;
  int tot = 0;
  for (ListNode *p = head; p; p = p->next) ++tot;
  k %= tot;
  if (k == 0) return head;
  ListNode *p = super_head;
  for (int i = 0; i < tot - k; i++) p = p->next;
  super_head->next = p->next;
  ListNode *tmp = p->next;
  p->next = NULL;
  while (tmp->next) tmp = tmp->next;
  tmp->next = head;
  return super_head->next;
}
