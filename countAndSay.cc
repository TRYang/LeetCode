string countAndSay(int n) {
  string cur = "1";
  for (int i = 1; i < n; i++) {
    string nxt;
    for (int j = 0, k; j < cur.length(); j = k) {
      for (k = j + 1; k < cur.length() && cur[k] == cur[j]; k++);
      char buf[100];
      sprintf(buf, "%d%d", k - j, cur[j] - '0');
      nxt += string(buf);
    }
    cur = nxt;
  }
  return cur;
}
