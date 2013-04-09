bool isPalindrome(string s) {
  for (int i = 0, j = s.length() - 1; i <= j; ) {
    while (i <= j && !isdigit(s[i]) && !isalpha(s[i])) ++i;
    while (i <= j && !isdigit(s[j]) && !isalpha(s[j])) --j;
    if (i > j) break;
    if (isdigit(s[i]) && isdigit(s[j])) {
      if (s[i] != s[j]) return false;
    } else
    if (isalpha(s[i]) && isalpha(s[j])) {
      if (tolower(s[i]) != tolower(s[j])) return false;
    } else return false;
    ++i;
    --j;
  }
  return true;
}
