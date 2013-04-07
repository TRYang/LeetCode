bool isInterleave(string s1, string s2, string s3) {
  if (s1.length() + s2.length() != s3.length()) return false;
  vector<bool> f[2];
  f[0].resize(s1.length() + 1);
  f[1].resize(s1.length() + 1);
  f[0][0] = true;
  for (int i = 0; i < s3.length(); i++) {
    int cur = (i & 1), nxt = (cur ^ 1);
    for (int j = 0; j <= s1.length() && j <= i; j++)
      if (f[cur][j]) {
        f[cur][j] = false;
        int k = i - j;
        if (j < s1.length() && s3[i] == s1[j]) f[nxt][j + 1] = true;
        if (k < s2.length() && s3[i] == s2[k]) f[nxt][j] = true;
      }
  }
  return f[s3.length() & 1][s1.length()];
}
