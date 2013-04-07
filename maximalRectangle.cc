int maximalRectangle(vector<vector<char> > &matrix) {
  if (matrix.size() == 0) return 0;
  vector<vector<int> > f;
  for (int i = 0; i < matrix.size(); i++) {
    vector<int> temp(matrix[i].size());
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] == '0') temp[j] = 0; else 
      if (i == 0) temp[j] = 1; else temp[j] = f[i - 1][j] + 1;
    }
    f.push_back(temp);
  }
  vector<vector<int> > left;
  for (int i = 0; i < matrix.size(); i++) {
    vector<int> temp(matrix[i].size());
    stack<int> stk;
    for (int j = 0; j < matrix[i].size(); j++) {
      while (!stk.empty() && f[i][stk.top()] >= f[i][j]) stk.pop();
      if (stk.empty()) temp[j] = -1; else temp[j] = stk.top();
      stk.push(j);
    }
    left.push_back(temp);
  }
  int area = 0;
  for (int i = 0; i < matrix.size(); i++) {
    stack<int> stk;
    for (int j = matrix[i].size() - 1; j >= 0; j--) {
      while (!stk.empty() && f[i][stk.top()] >= f[i][j]) stk.pop();
      int right = matrix[i].size();
      if (!stk.empty()) right = stk.top();
      stk.push(j);
      area = max(area, f[i][j] * (right - left[i][j] - 1));
    }
  }
  return area;
}
