int removeDuplicates(int A[], int n) {
  int m = 0;
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && A[j] == A[i]; j++);
    for (int k = 0; k < min(2, j - i); k++) A[m++] = A[i + k];
  }
  return m;
}
