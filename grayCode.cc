vector<int> grayCode(int n) {
  vector<int> ret;
  ret.push_back(0);
  for (int i = 1; i < (1 << n); i++) ret.push_back(i ^ (i >> 1));
  return ret;
}
