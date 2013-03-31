double pow(double x, int n) {
  double ret = 1;
  int sign = 1;
  if (n < 0) {
    sign = 0;
    n = (n + 1) * (-1);
  }
  double y = x;
  while (n) {
    if (n & 1) ret *= y;
    y *= y;
    n >>= 1;
  }
  if (sign == 0) {
    ret *= x;
    ret = 1 / ret;
  }
  return ret;
}
