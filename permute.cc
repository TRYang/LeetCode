void dfs(const vector<int> &num, int n, int mask, vector<int> &per, vector<vector<int> > &ret) {
  if (mask == (1 << n) - 1) {
    ret.push_back(per);
    return;
  }
  for (int i = 0; i < n; i++)
    if ((mask & (1 << i)) == 0) {
      per.push_back(num[i]);
      dfs(num, n, mask | (1 << i), per, ret);
      per.pop_back();
    }
}
vector<vector<int> > permute(vector<int> &num) {
  sort(num.begin(), num.end());
  vector<vector<int> > ret;
  if (num.size() == 0) return ret;
  int n = 1;
  for (int i = 1; i < num.size(); i++)
    if (num[i] != num[n - 1]) num[n++] = num[i];
  vector<int> per;
  dfs(num, n, 0, per, ret);
  return ret;
}
