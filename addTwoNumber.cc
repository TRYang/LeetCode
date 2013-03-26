/*
 * struct {
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 * */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode(-1);
    ListNode *cur = ret;
    int carry = 0;
    while (l1 != NULL || l2 != NULL) {
      int value = carry;
      if (l1 != NULL) {
        value += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        value += l2->val;
        l2 = l2->next;
      }
      cur->next = new ListNode(value / 10);
      cur = cur->next;
      carry = value % 10;
    }
    if (carry) {
      cur->next = new ListNode(carry);
    }
    return ret->next;
  }
};
