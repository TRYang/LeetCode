int minDistance(string word1, string word2) {
  if (word1.length() < word2.length()) swap(word1, word2);
  if (word1 == "") return 0;
  vector<int> f[2];
  for (int i = 0; i < 2; i++) f[i].resize(word2.length() + 1);
  for (int i = 0; i <= word2.length(); i++) f[0][i] = i;
  for (int i = 0; i < word1.length(); i++) {
    int cur = (i & 1), nxt = (cur ^ 1);
    char c = word1[i];
    f[nxt][0] = f[cur][0] + 1;
    for (int j = 0; j < word2.length(); j++) {
      char d = word2[j];
      if (c == d) {
        f[nxt][j + 1] = min(f[cur][j + 1], f[nxt][j]) + 1;
        f[nxt][j + 1] = min(f[nxt][j + 1], f[cur][j]);
      } else {
        f[nxt][j + 1] = min(f[cur][j + 1], f[nxt][j]) + 1;
        f[nxt][j + 1] = min(f[nxt][j + 1], f[cur][j] + 1);
      }
    }
  }
  return f[word1.length() & 1][word2.length()];
}
