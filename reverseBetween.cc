pair<ListNode*, ListNode*> change(int dep, int n, ListNode *p) {
  if (dep == n - 1) {
    return make_pair(p, p->next);
  }
  pair<ListNode*, ListNode*> ret = change(dep + 1, n, p->next);
  p->next->next = p;
  return ret;
}
ListNode *reverseBetween(ListNode *head, int m, int n) {
  if (!head) return head;
  ListNode *super_head = new ListNode(0);
  super_head->next = head;
  ListNode *p = super_head;
  for (int i = 1; i < m; i++) p = p->next;
  pair<ListNode*, ListNode*> pptr = change(0, n - m + 1, p->next);
  p->next->next = pptr.second;
  p->next = pptr.first;
  return super_head->next;
}
