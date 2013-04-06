void merge(int A[], int m, int B[], int n) {
  int dn = m + n;
  int p = m - 1, q = n - 1;
  while (dn) {
    if (p >= 0 && (q == -1 || A[p] > B[q])) {
      A[--dn] = A[p--];
    } else {
      A[--dn] = B[q--];
    }
  }
}
