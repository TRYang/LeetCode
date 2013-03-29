bool isValidSudoku(vector<vector<char> > &board) {
  vector<int> cols_mask(9), rows_mask(9), block_mask(9);
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') continue;
      int c = board[i][j] - '0' - 1;
      int blk = (i / 3) * 3 + j / 3;
      if (rows_mask[i] & (1 << c)) return false;
      if (cols_mask[j] & (1 << c)) return false;
      if (block_mask[blk] & (1 << c)) return false;
      rows_mask[i] |= (1 << c);
      cols_mask[j] |= (1 << c);
      block_mask[blk] |= (1 << c);
    }
  return true;
}
