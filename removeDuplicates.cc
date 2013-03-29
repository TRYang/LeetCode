int removeDuplicates(int A[], int n) {
  int m = 0;
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && A[j] == A[i]; j++);
    A[m++] = A[i];
  }
  return m;
}
