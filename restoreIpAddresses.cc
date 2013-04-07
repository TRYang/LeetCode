int check(const string &s) {
  if (s.length() == 1) {
    return 1;
  } else 
  if (s.length() == 2) {
    return s[0] != '0';
  } else {
    int value = (s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0';
    return s[0] != '0' && value <= 255;
  }
}
void dfs(int dep, string s, string ip, vector<string> &ret) {
  if (dep == 4) {
    if (s == "") ret.push_back(ip);
    return;
  }
  if (s == "") return;
  for (int i = 0; i < 3; i++) {
    if (i + 1 > s.length()) break;
    if (check(s.substr(0, i + 1))) {
      if (dep == 0)
        dfs(dep + 1, s.substr(i + 1), s.substr(0, i + 1), ret);
      else
        dfs(dep + 1, s.substr(i + 1), ip + "." + s.substr(0, i + 1), ret);
    }
  }
}
vector<string> restoreIpAddresses(string s) {
  vector<string> ret;
  dfs(0, s, "", ret);
  return ret;
}
