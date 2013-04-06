ListNode *partition(ListNode *head, int x) {
  ListNode *small = new ListNode(0);
  ListNode *large = new ListNode(0);
  ListNode *tsmall = small, *tlarge = large;
  for (ListNode *ptr = head; ptr; ptr = ptr->next)
    if (ptr->val < x) {
      small->next = ptr;
      small = ptr;
    } else {
      large->next = ptr;
      large = ptr;
    }
  large->next = NULL;
  small->next = tlarge->next;
  return tsmall->next;
}
