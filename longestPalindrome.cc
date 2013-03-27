string longestPalindrome(string s) {
  vector<int> Z(s.length());
  int max_len = 0;
  pair<int, int> res;
  int ptr = -1;
  //even length
  for (int i = 0; i < s.length() - 1; i++) {
    int match_len;
    if (ptr == -1 || ptr + Z[ptr] <= i)
      match_len = 0;
    else
      match_len = min(ptr + Z[ptr] - i, Z[2 * ptr - i]);
    while (i - match_len >= 0 && i + match_len + 1 < s.length() && s[i - match_len] == s[i + match_len + 1]) ++match_len;
    Z[i] = match_len;
    if (Z[i] * 2 > max_len) {
      max_len = Z[i] * 2;
      res = make_pair(i - Z[i] + 1, i + Z[i]);
    }
    if (ptr == -1 || i + Z[i] > ptr + Z[ptr]) ptr = i;
  }
  //odd length
  ptr = -1;
  for (int i = 0; i < s.length(); i++) {
    int match_len;
    if (ptr == -1 || ptr + Z[ptr] - 1 < i)
      match_len = 0;
    else
      match_len = min(ptr + Z[ptr] - i, Z[2 * ptr - i]);
    while (i - match_len >= 0 && i + match_len < s.length() && s[i - match_len] == s[i + match_len]) ++match_len;
    Z[i] = match_len;
    if (Z[i] * 2 - 1 > max_len) {
      max_len = Z[i] * 2 - 1;
      res = make_pair(i - Z[i] + 1, i + Z[i] - 1);
    }
    if (ptr == -1 || i + Z[i] > ptr + Z[ptr]) ptr = i;
  }
  return s.substr(res.first, res.second - res.first + 1);
}
