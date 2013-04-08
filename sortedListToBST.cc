TreeNode *build(ListNode *head, int n) {
  if (n == 0) return NULL;
  int mid = n >> 1;
  ListNode *p = head;
  for (int i = 0; i < mid; i++) p = p->next;
  TreeNode *cur = new TreeNode(p->val);
  cur->left = build(head, mid);
  cur->right = build(p->next, n - 1 - mid);
  return cur;
}
TreeNode *sortedListToBST(ListNode *head) {
  int n = 0;
  for (ListNode *p = head; p; p = p->next) ++n;
  return build(head, n);
}
