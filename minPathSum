int minPathSum(vector<vector<int> > &grid) {
  vector<vector<int> > f(grid);
  int ret;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (i == 0 && j == 0) f[i][j] = grid[i][j];
      else if (i == 0) f[i][j] = f[i][j - 1] + grid[i][j];
      else if (j == 0) f[i][j] = f[i - 1][j] + grid[i][j];
      else f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
      ret = f[i][j];
    }
  }
  return ret;
}
