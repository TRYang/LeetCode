int longestValidParentheses(string s) {
  stack<int> stk;
  while (!stk.empty()) stk.pop();
  stk.push(-1);
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      if (stk.size() == 1) {
        stk.pop();
        stk.push(i);
      } else {
        stk.pop();
        ans = max(ans, i - stk.top());
      }
    }
  }
  return ans;
}
