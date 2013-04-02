void setZeroes(vector<vector<int> > &matrix) {
  if (matrix.size() == 0) return;
  vector<bool> rows(matrix.size()), cols(matrix[0].size());
  for (int i = 0; i < matrix.size(); i++)
    for (int j = 0; j < matrix[i].size(); j++)
      if (!matrix[i][j]) {
        rows[i] = true;
        cols[j] = true;
      }
  for (int i = 0; i < matrix.size(); i++)
    for (int j = 0; j < matrix[i].size(); j++)
      if (rows[i] || cols[j]) matrix[i][j] = 0;
}
