void dfs(int dep, int n, int tot, int m, vector<int> &path, vector<vector<int> > &ret) {
  if (dep > n) {
    if (tot == m) ret.push_back(path);
    return;
  }
  if (tot + n - dep + 1 < m) return;
  if (tot < m) {
    path[tot] = dep;
    dfs(dep + 1, n, tot + 1, m, path, ret);
  }
  dfs(dep + 1, n, tot, m, path, ret);
}
vector<vector<int> > combine(int n, int k) {
  vector<vector<int> > ret;
  vector<int> path(k);
  dfs(1, n, 0, k, path, ret);
  return ret;
}
