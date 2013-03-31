string getPermutation(int n, int k) {
  --k;
  int fac[n];
  fac[0] = 1;
  for (int i = 1; i < n; i++) fac[i] = fac[i - 1] * i;
  string ret;
  for (int i = 0, mask = 0; i < n; i++) {
    int p = 0;
    while (mask & (1 << p)) ++p;
    while (k >= fac[n - 1 - i]) {
      ++p;
      while (mask & (1 << p)) ++p;
      k -= fac[n - 1 - i];
    }
    ret += '1' + p;
    mask |= 1 << p;
  }
  return ret;
}
