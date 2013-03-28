string longestCommonPrefix(vector<string> &strs) {
  if (strs.size() == 0) return "";
  int ans = 0;
  while (true) {
    bool flag = true;
    char c = 0;
    for (int i = 0; i < strs.size(); i++) {
      if (ans >= strs[i].length()) {
        flag = false;
        break;
      }
      if (!c) c = strs[i][ans];
      if (strs[i][ans] != c) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
    ++ans;
  }
  return strs[0].substr(0, ans);
}
