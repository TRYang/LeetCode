int numDistinct(string S, string T) {
  vector<int> f[2];
  f[0].resize(T.length() + 1);
  f[1].resize(T.length() + 1);
  f[0][0] = 1;
  for (int i = 0; i < S.length(); i++) {
    int cur = (i & 1), nxt = (cur ^ 1);
    for (int j = 0; j <= T.length(); j++) {
      f[nxt][j] += f[cur][j];
      if (j < T.length() && S[i] == T[j]) f[nxt][j + 1] += f[cur][j];
      f[cur][j] = 0;
    }
  }
  return f[S.length() & 1][T.length()];
}
