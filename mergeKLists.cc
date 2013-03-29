ListNode *mergeKLists(vector<ListNode*> &lists) {
  ListNode *head = NULL, *cur = NULL;
  while (true) {
    ListNode *best = NULL;
    int index = -1;
    for (int i = 0; i < lists.size(); i++)
      if (lists[i]) {
        if (!best || lists[i]->val < best->val) {
          best = lists[i];
          index = i;
        }
      }
    if (index == -1) break;
    if (head == NULL) head = best;
    if (cur) cur->next = best;
    cur = best;
    lists[index] = best->next;
  }
  return head;
}
