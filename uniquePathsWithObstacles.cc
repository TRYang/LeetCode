int uniquePathsWithObstacles(vector<vector<int> > &obstacles) {
  vector<vector<int> > f(obstacles);
  int ret = 0;
  for (int i = 0; i < f.size(); i++) {
    for (int j = 0; j < f[i].size(); j++) {
      if (obstacles[i][j]) {
        f[i][j] = 0;
        continue;
      }
      if (i == 0 && j == 0) {
        f[i][j] = 1;
        continue;
      }
      f[i][j] = 0;
      if (i) f[i][j] += f[i - 1][j];
      if (j) f[i][j] += f[i][j - 1];
    }
  }
  return f[f.size() - 1][f[0].size() - 1];
}
