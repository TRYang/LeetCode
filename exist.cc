int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int move(int x, int y, int k, int n, int m) {
  x += mx[k];
  y += my[k];
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}
bool dfs(int x, int y, vector<vector<bool> > &used, vector<vector<char> > &board, int dep, const string &word) {
  if (used[x][y]) return false;
  if (board[x][y] != word[dep - 1]) return false;
  used[x][y] = true;
  if (dep == word.length()) return true;
  for (int i = 0; i < 4; i++)
    if (move(x, y, i, board.size(), board[0].size()) && dfs(x + mx[i], y + my[i], used, board, dep + 1, word))
      return true;
  used[x][y] = false;
  return false;
}
bool exist(vector<vector<char> > &board, string word) {
  vector<vector<bool> > used;
  for (int i = 0; i < board.size(); i++) {
    vector<bool> temp(board[i].size());
    used.push_back(temp);
  }
  if (word.length() == 0) return true;
  for (int i = 0; i < board.size(); i++)
    for (int j = 0; j < board[i].size(); j++)
      if (board[i][j] == word[0] && dfs(i, j, used, board, 1, word))
        return true;
  return false;
}
