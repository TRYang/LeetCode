vector<int> rows, cols, block;
int bit_count[1 << 9];
bool dfs(vector<vector<char> > &board) {
  int min_choice;
  int x = -1, y = -1;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') continue;
      int left = (rows[i] & cols[j] & block[i / 3 * 3 + j / 3]);
      if (left == 0) return false;
      if (x == -1 || bit_count[left] < min_choice) {
        min_choice = bit_count[left];
        x = i;
        y = j;
      }
    }
  if (x == -1) return true;
  int mask = (rows[x] & cols[y] & block[x / 3 * 3 + y / 3]);
  for (int i = 0; i < 9; i++)
    if ((mask & (1 << i)) > 0) {
      board[x][y] = '1' + i;
      rows[x] ^= (1 << i);
      cols[y] ^= (1 << i);
      block[x / 3 * 3 + y / 3] ^= (1 << i);
      if (dfs(board)) return true;
      rows[x] ^= (1 << i);
      cols[y] ^= (1 << i);
      block[x / 3 * 3 + y / 3] ^= (1 << i);
      board[x][y] = '.';
    }
  return false;
}
void solveSudoku(vector<vector<char> > &board) {
  for (int i = 0; i < (1 << 9); i++) {
    bit_count[i] = 0;
    for (int k = i; k; k >>= 1) bit_count[i] += (k & 1);
  }
  rows.resize(9);
  cols.resize(9);
  block.resize(9);
  for (int i = 0; i < 9; i++) rows[i] = cols[i] = block[i] = (1 << 9) - 1;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (board[i][j] != '.') {
        int c = board[i][j] - '1';
        rows[i] ^= (1 << c);
        cols[j] ^= (1 << c);
        block[i / 3 * 3 + j / 3] ^= (1 << c);
      }
  dfs(board);
}
