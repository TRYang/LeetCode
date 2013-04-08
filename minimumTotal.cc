int minimumTotal(vector<vector<int> > &triangle) {
  if (triangle.size() == 0) return 0;
  vector<int> f[2];
  f[0].resize(triangle.size());
  f[1].resize(triangle.size());
  f[0][0] = triangle[0][0];
  int ans;
  if (triangle.size() == 1) ans = f[0][0];
  for (int i = 1; i < triangle.size(); i++) {
    int cur = (i - 1) & 1, nxt = cur ^ 1;
    f[nxt][0] = f[cur][0] + triangle[i][0];
    f[nxt][i] = f[cur][i - 1] + triangle[i][i];
    for (int j = 1; j < i; j++)
      f[nxt][j] = min(f[cur][j - 1], f[cur][j]) + triangle[i][j];
    if (i + 1 == triangle.size()) {
      ans = f[nxt][0];
      for (int j = 1; j <= i; j++) ans = min(ans, f[nxt][j]);
    }
  }
  return ans;
}
