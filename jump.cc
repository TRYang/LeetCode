int jump(int A[], int n) {
  if (n == 0) return 0;
  deque<int> dq;
  vector<int> f(n);
  dq.push_back(0);
  f[0] = 0;
  for (int i = 1; i < n; i++) {
    while (!dq.empty() && A[dq.front()] + dq.front() < i) dq.pop_front();
    if (!dq.empty()) {
      f[i] = f[dq.front()] + 1;
      while (!dq.empty() && f[dq.back()] == f[i] && A[dq.back()] + dq.back() < A[i] + i) dq.pop_back();
      dq.push_back(i);
    }
  }
  return f[n - 1];
}
