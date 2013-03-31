vector<vector<int> > generateMatrix(int n) {
  vector<vector<int> > ret;
  vector<int> tmp(n);
  for (int i = 0; i < n; i++) ret.push_back(tmp);
  int id = 0;
  for (int i = 0 ; i < n / 2; i++) {
    int len = n - 1 - 2 * i;
    for (int j = 0; j < len; j++) ret[i][i + j] = ++id;
    for (int j = 0; j < len; j++) ret[i + j][n - 1 - i] = ++id;
    for (int j = 0; j < len; j++) ret[n - 1 - i][n - 1 - i - j] = ++id;
    for (int j = 0; j < len; j++) ret[n - 1 - i - j][i] = ++id;
  }
  if (n % 2 == 1) ret[n / 2][n / 2] = ++id;
  return ret;
}
