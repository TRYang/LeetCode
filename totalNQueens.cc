int dfs(int dep, const int &n, int col_mask, int dia_mask1, int dia_mask2) {
  if (dep == n) return 1;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int c = dep + i, d = dep - i + n - 1;
    if (col_mask & (1 << i)) continue;
    if (dia_mask1 & (1 << c)) continue;
    if (dia_mask2 & (1 << d)) continue;
    tot += dfs(dep + 1, n, col_mask | (1 << i), dia_mask1 | (1 << c), dia_mask2 | (1 << d));
  }
  return tot;
}
int totalNQueens(int n) {
  return dfs(0, n, 0, 0, 0);
}
