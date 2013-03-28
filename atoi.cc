int atoi(const char *str) {
  char *ptr =(char*) str;
  while (ptr && (*ptr) == ' ') ptr++;
  if (!ptr || (*ptr != '-' && *ptr != '+' && !isdigit(*ptr))) return 0;
  int value = 0;
  int sign = 1;
  if (!isdigit(*ptr) && *ptr == '-') sign = -1;
  if (!isdigit(*ptr)) ptr++;
  while (ptr) {
    if (!isdigit(*ptr)) break;
    if (sign == 1) {
      if (value > (INT_MAX - *ptr - '0') / 10) return INT_MAX;
      value = value * 10 + *ptr - '0';
    } else {
      if (value > -((INT_MIN + *ptr - '0') / 10)) return INT_MIN;
      value = value * 10 + *ptr - '0';
    }
    ptr++;
  }
  return value * sign;
}
