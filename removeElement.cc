int removeElement(int A[], int n, int elem) {
  for (int i = 0; i < n; ) {
    if (A[i] == elem) {
      swap(A[i], A[n - 1]);
      --n;
    } else ++i;
  }
  return n;
}
