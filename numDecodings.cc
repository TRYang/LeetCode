int check(char a, char b) {
  if (a == '1') return 1;
  if (a == '2') return b <= '6';
  return 0;
}
int numDecodings(string s) {
  if (s == "") return 0;
  vector<int> f(s.length() + 1);
  f[0] = 1;
  for (int i = 0; i < s.length(); i++) {
    f[i + 1] = 0;
    if (s[i] != '0') f[i + 1] += f[i];
    if (i && check(s[i - 1], s[i])) f[i + 1] += f[i - 1];
  }
  return f[s.length()];
}
