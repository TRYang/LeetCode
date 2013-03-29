pair<bool, ListNode*> change(int dep, const int &target, ListNode *p, ListNode *q, ListNode *start) {
  if (!q) return make_pair(false, p);
  if (dep == target) {
    start->next = q->next;
    q->next = p;
    return make_pair(true, q);
  }
  pair<bool, ListNode*> temp = change(dep + 1, target, q, q->next, start);
  if (temp.first) {
    q->next = p;
    return temp;
  } else return make_pair(false, p);
}
ListNode *reverseKGroup(ListNode *head, int k) {
  if (k == 1) return head;
  ListNode *super_head = new ListNode(-1);
  ListNode *cur = super_head;
  cur->next = head;
  while (true) {
    ListNode *nxt = cur->next;
    if (!nxt) break;
    pair<bool, ListNode*> temp = change(2, k, nxt, nxt->next, nxt);
    if (!temp.first) break;
    cur->next = temp.second;
    cur = nxt;
  }
  return super_head->next;
}
