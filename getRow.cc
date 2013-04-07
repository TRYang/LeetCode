int Combination(int n, int m) {
  long long ret = 1;
  for (int i = 0; i < m; i++) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}
vector<int> getRow(int rowIndex) {
  vector<int> ret;
  for (int i = 0; i <= rowIndex; i++) ret.push_back(Combination(rowIndex, i));
  return ret;
}
