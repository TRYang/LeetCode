bool isMatch(const char *s, const char *p) {
  int length = strlen(s);
  std::vector<bool> match(length + 1);
  match[0] = true;
  for (char *ptr = (char*)p; *ptr; ptr++) {
    int minp = length + 2;
    for (int i = 0; i <= length; i++)
      if (match[i]) {
        minp = i;
        break;
      }
    for (int i = length; i > 0; i--) {
      char *st = (char*)s;
      st += i - 1;
      if (*ptr == '?') {
        match[i] = match[i - 1];
      } else
      if (*ptr == '*') {
        if (minp <= i) match[i] = true;
        else match[i] = false;
      } else {
        if (*ptr == *st) match[i] = match[i - 1];
        else match[i] = false;
      }
    }
    if (match[0] && *ptr == '*') match[0] = true; else match[0] = false;
  }
  return match[length];
}
