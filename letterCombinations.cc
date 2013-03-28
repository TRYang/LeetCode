void dfs(const string &digits, int dep, char *s, const string &keys, vector<string> &ret) {
  if (dep == digits.length()) {
    string tmp = s;
    ret.push_back(tmp);
    return;
  }
  int start = keys.find(digits[dep]);
  while (start < keys.length() && keys[start] == digits[dep]) {
    *(s + dep) = 'a' + start;
    dfs(digits, dep + 1, s, keys, ret);
    start++;
  }
}
vector<string> letterCombinations(string digits) {
  string keys = "22233344455566677778889999";
  vector<string> ret(0);
  char s[digits.length() + 1];
  dfs(digits, 0, s, keys, ret);
  return ret;
}
