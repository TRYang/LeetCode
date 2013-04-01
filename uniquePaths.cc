int C(int n, int m) {
  if (m == 0 || n == m) return 1;
  if (m > n - m) m = n - m;
  long long ret = 1;
  for (int i = 0; i < m; i++) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}
int uniquePaths(int m, int n) {
  return C(m + n - 2, n - 1);
}
