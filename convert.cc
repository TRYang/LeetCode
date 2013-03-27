string convert(string s, int nRows) {
  if (nRows >= s.length() || nRows == 1) return s;

  vector<int> head(nRows);
  for (int i = 0; i < nRows; i++) head[i] = -1;

  vector<int> next(s.length());

  int delta = 1, cur_row = 0;
  for (int i = 0; i < s.length(); i++) {
    if (head[cur_row] != -1) next[head[cur_row]] = i;
    next[i] = -1;
    head[cur_row] = i;
    if (cur_row + delta < 0 || cur_row + delta >= nRows) delta *= -1;
    cur_row += delta;
  }

  string ret;
  for (int i = 0; i < nRows; i++)
    for (int j = i; j != -1; j = next[j]) ret += s[j];
  return ret;
}
