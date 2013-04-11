int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
void floodfill(vector<vector<char> > &board, vector<vector<bool> > &used, int sx, int sy) {
  queue<pair<int, int> > q;
  vector<pair<int, int> > vec;
  q.push(make_pair(sx, sy));
  bool flag = false;
  used[sx][sy] = true;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    vec.push_back(q.front());
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = x + mx[i], ty = y + my[i];
      if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[sx].size()) {
        flag = true;
        continue;
      }
      if (board[tx][ty] == 'O' && !used[tx][ty]) {
        used[tx][ty] = true;
        q.push(make_pair(tx, ty));
      }
    }
  }
  if (!flag) {
    for (int i = 0; i < vec.size(); i++) board[vec[i].first][vec[i].second] = 'X';
  }
}
void solve(vector<vector<char> > &board) {
  if (board.size() == 0) return;
  vector<vector<bool> > used;
  for (int i = 0; i < board.size(); i++) {
    vector<bool> temp(board[i].size());
    used.push_back(temp);
  }
  for (int i = 0; i < board.size(); i++)
    for (int j = 0; j < board[i].size(); j++)
      if (board[i][j] == 'O' && !used[i][j]) floodfill(board, used, i, j);
}
