bool dp(map<pair<string, string>, bool> &dict, string s1, string s2) {
  pair<string, string> ps = make_pair(s1, s2);
  if (dict.find(ps) != dict.end()) return dict[ps];
  if (s1.length() == 1) dict[ps] = (s1 == s2);
  if (s1 == s2 || s1 == string(s2.rbegin(), s2.rend())) return dict[ps] = true;
  int cnt[26];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < s1.length(); i++) cnt[s1[i] - 'a']++;
  for (int i = 0; i < s1.length(); i++) cnt[s2[i] - 'a']--;
  for (int i = 0; i < 26; i++)
    if (cnt[i] != 0) return false;

  for (int i = 0; i < s1.length() - 1; i++)
    if (dp(dict, s1.substr(0, i + 1), s2.substr(0, i + 1)) && dp(dict, s1.substr(i + 1), s2.substr(i + 1))) return dict[ps] = true;
  for (int i = 0; i < s1.length() - 1; i++) {
    int l1 = i + 1, l2 = s1.length() - l1;
    if (dp(dict, s1.substr(0, l1), s2.substr(l2)) && dp(dict, s1.substr(l1), s2.substr(0, l2))) return dict[ps] = true;
  }
  return dict[ps] = false;
}
bool isScramble(string s1, string s2) {
  if (s1.length() != s2.length()) return false;
  map<pair<string, string>, bool> dict;
  return dp(dict, s1, s2);
}
