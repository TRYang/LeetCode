int trap(int A[], int n) {
  stack<int> stk;
  vector<int> sum(n + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + A[i - 1];
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (!stk.empty() && A[stk.top()] > A[i]) continue;
    if (!stk.empty()) total += (i - stk.top() - 1) * A[stk.top()] - sum[i] + sum[stk.top() + 1];
    stk.push(i);
  }
  while (!stk.empty()) stk.pop();
  for (int i = n - 1; i >= 0; i--) {
    if (!stk.empty() && A[stk.top()] >= A[i]) continue;
    if (!stk.empty()) total += (stk.top() - i - 1) * A[stk.top()] - sum[stk.top()] + sum[i + 1];
    stk.push(i);
  }
  return total;
}
