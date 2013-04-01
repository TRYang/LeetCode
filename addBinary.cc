string addBinary(string a, string b) {
  int carry = 0;
  string c;
  for (int i = 0; i < max(a.length(), b.length()); i++) {
    int xa = (i >= a.length() ? 0 : a[a.length() - 1 - i] - '0');
    int xb = (i >= b.length() ? 0 : b[b.length() - 1 - i] - '0');
    carry += xa + xb;
    c = to_string(carry & 1) + c;
    carry >>= 1;
  }
  if (carry) c = to_string(carry) + c;
  return c;
}
