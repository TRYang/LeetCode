double pow(double x, int n) {
  double ret = 1;
  int sign = 1;
  if (n < 0) {
    sign = -1;
    n = (n + 1) * (-1);
  }
  double y = x;
  while (n) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  if (sign == -1) {
    ret *= y;
    ret = 1 / ret;
  }
  return ret;
}
