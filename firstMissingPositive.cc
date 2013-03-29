int firstMissingPositive(int A[], int n) {
  if (n == 0) return 1;
  for (int i = 0, j = n - 1; i < j; ) {
    while (i < n && A[i] > 0) ++i;
    while (j >= 0 && A[j] <= 0) --j;
    if (i <= j) {
      swap(A[i], A[j]);
      ++i;
      --j;
    }
  }
  while (n > 0 && A[n - 1] <= 0) --n;
  if (n == 0) return 1;
  for (int i = 0; i < n; i++) {
    while (true) {
      if (A[i] == i + 1 || A[i] > n) break;
      if (A[i] == A[A[i] - 1]) break;
      swap(A[i], A[A[i] - 1]);
    }
  }
  for (int i = 0; i < n; i++)
    if (A[i] != i + 1) return i + 1;
  return n + 1;
}
