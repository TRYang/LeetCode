ListNode *deleteDuplicates(ListNode *head) {
  ListNode *super_head = new ListNode(-1);
  super_head->next = head;
  for (ListNode *ptr = super_head; ptr->next; ) {
    int val = ptr->next->val;
    int tot = 1;
    ListNode *q = ptr->next;
    while (q->next && q->next->val == val) {
      q = q->next;
      ++tot;
    }
    if (tot == 1) {
      ptr = ptr->next;
    } else {
      ptr->next = q->next;
    }
  }
  return super_head->next;
}
