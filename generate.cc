vector<vector<int> > generate(int numRows) {
  vector<vector<int> > ret;
  for (int i = 1; i <= numRows; i++) {
    vector<int> temp(i);
    temp[0] = temp[i - 1] = 1;
    for (int j = 1; j < i - 1; j++) temp[j] = ret[i - 2][j - 1] + ret[i - 2][j];
    ret.push_back(temp);
  }
  return ret;
}
