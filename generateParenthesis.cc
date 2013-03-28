void dfs(int dep, int end, int left, int stn, char *s, vector<string> &ret) {
  if (dep == end) {
    string tmp = s;
    ret.push_back(tmp);
    return;
  }
  if (left) {
    s[dep] = '(';
    dfs(dep + 1, end, left - 1, stn + 1, s, ret);
  }
  if (stn) {
    s[dep] = ')';
    dfs(dep + 1, end, left, stn - 1, s, ret);
  }
}
vector<string> generateParenthesis(int n) {
  vector<string> ret(0);
  char s[2 * n + 1];
  s[2 * n] = 0;
  dfs(0, 2 * n, n, 0, s, ret);
  return ret;
}
