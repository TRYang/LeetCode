int move_x[4] = {0, 1, 0, -1};
int move_y[4] = {1, 0, -1, 0};
int check(int x, int y, int d, const int &n, const int &m, vector<bool> &visited) {
  x += move_x[d];
  y += move_y[d];
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  return visited[x * m + y] == false;
}
vector<int> spiralOrder(vector<vector<int> > &matrix) {
  int n = matrix.size();
  vector<int> ret;
  if (n == 0) return ret;
  int m = matrix[0].size();
  vector<bool> visited(n * m);
  int x = 0, y = 0, dir = 0;
  for (int t = 0; t < n * m; t++) {
    ret.push_back(matrix[x][y]);
    visited[x * m + y] = true;
    if (t == n * m - 1) break;
    while (!check(x, y, dir, n, m, visited)) dir = (dir + 1) % 4;
    x += move_x[dir];
    y += move_y[dir];
  }
  return ret;
}
