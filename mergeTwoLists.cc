ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode(-1);
  ListNode *p = head;
  while (l1 || l2) {
    if (!l2 || (l1 && l1->val < l2->val)) {
      p->next = l1;
      l1 = l1->next;
    } else {
      p->next = l2;
      l2 = l2->next;
    }
    p = p->next;
  }
  return head->next;
}
