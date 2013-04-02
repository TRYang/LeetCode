bool searchMatrix(vector<vector<int> > &matrix, int target) {
  if (matrix.size() == 0) return false;
  int n = matrix[0].size() - 1;
  for (int i = 0; i < matrix.size(); i++) {
    while (n >= 0 && matrix[i][n] > target) --n;
    if (n >= 0 && matrix[i][n] == target) return true;
  }
  return false;
}
