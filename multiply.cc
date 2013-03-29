string multiply(string num1, string num2) {
  vector<int> res(num1.length() + num2.length());
  for (int i = 0; i < num1.length(); i++) {
    int carry = 0;
    int x = num1[num1.length() - 1 - i] - '0';
    for (int j = 0; j < num2.length(); j++) {
      int y = num2[num2.length() - 1 - j] - '0';
      res[i + j] += carry + x * y;
      carry = res[i + j] / 10;
      res[i + j] %= 10;
    }
    if (carry) res[i + num2.length()] += carry;
  }
  string ret;
  for (int i = num1.length() + num2.length() - 1, first = 0; i >= 0; i--) {
    if (res[i] || first || i == 0) {
      ret += '0' + res[i];
      first = 1;
    }
  }
  return ret;
}
