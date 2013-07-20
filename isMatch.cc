bool isMatch(const char *s, const char *p) {
  int n = strlen(s), m = strlen(p);
  vector<vector<int> > f;
  for (int i = 0; i <= m; i++) {
    vector<int> tmp(n + 1, 0);
    f.push_back(tmp);
  }
  f[0][0] = 1;
  for (int i = 0; i < m; ) {
    char c = p[i];
    int flag = 0;
    if (i < m - 1 && p[i + 1] == '*') {
      flag = 1;
    }
    int nxt = i + 1 + flag;
    if (flag) {
      f[nxt][0] = f[i][0];
    }
    for (int j = 0; j < n; ) {
      if (!flag) {
        if (s[j] == c || c == '.') {
          f[nxt][j + 1] = f[i][j];
        } else {
        }
        ++j;
      } else {
        if (s[j] == c || c == '.') {
          int value = f[i][j];
          while (j < n && (s[j] == c || c == '.')) {
            value |= f[i][j + 1];
            f[nxt][j + 1] |= value;
            ++j;
          }
        } else {
          f[nxt][j + 1] = f[i][j + 1];
          ++j;
        }
      }
    }
    i = nxt;
  }
  return f[m][n];
}
