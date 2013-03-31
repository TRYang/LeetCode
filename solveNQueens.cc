void dfs(int dep, const int &n, int col_mask, int dia_mask1, int dia_mask2, vector<int> &stat, vector<vector<string> > &ret) {
  if (dep == n) {
    vector<string> board;
    for (int i = 0; i < n; i++) {
      string row_stat(n, '.');
      row_stat[stat[i]] = 'Q';
      board.push_back(row_stat);
    }
    ret.push_back(board);
    return;
  }
  for (int i = 0; i < n; i++) {
    int c = dep + i, d = dep - i + n - 1;
    if (col_mask & (1 << i)) continue;
    if (dia_mask1 & (1 << c)) continue;
    if (dia_mask2 & (1 << d)) continue;
    stat[dep] = i;
    dfs(dep + 1, n, col_mask | (1 << i), dia_mask1 | (1 << c), dia_mask2 | (1 << d), stat, ret);
  }
}
vector<vector<string> > solveNQueens(int n) {
  vector<vector<string> > ret;
  vector<int> stat(n);
  dfs(0, n, 0, 0, 0, stat, ret);
  return ret;
}
