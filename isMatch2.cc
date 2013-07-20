bool isMatch(const char *s, const char *p) {
  int n = strlen(s), m = strlen(p);
  int *cur = new int[n + 1];
  int *nxt = new int[n + 1];
  for (int i = 0; i <= n; i++) cur[i] = (i == 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) nxt[j] = 0;
    char c = p[i];
    if (c == '*') {
      int value = cur[0];
      nxt[0] = cur[0];
      for (int j = 0; j < n; j++) {
        value |= cur[j + 1];
        nxt[j + 1] = value;
      }
    } else {
      for (int j = 0; j < n; j++) {
        if (s[j] == c || c == '?') {
          nxt[j + 1] = cur[j];
        }
      }
    }
    int *temp;
    temp = cur;
    cur = nxt;
    nxt = temp;
  }
  int ans = cur[n];
  delete cur;
  delete nxt;
  return ans;
}
