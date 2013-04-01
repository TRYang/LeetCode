int lengthOfLastWord(const char *s) {
  int ret = 0, flag = 0;
  for (char *st = (char*)s; *st; st++) {
    if (*st == ' ') {
      flag = 0;
      continue;
    }
    if (!flag) {
      ret = 1;
      flag = 1;
    } else ret++;
  }
  return ret;
}
