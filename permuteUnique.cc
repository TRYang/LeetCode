void dfs(vector<pair<int, int> > &count, int group, int id, int last, int mask, vector<int> &per, vector<vector<int> > &ret) {
  if (group == count.size()) {
    ret.push_back(per);
    return;
  }
  for (int i = last + 1; i < per.size(); i++)
    if ((mask & (1 << i)) == 0) {
      per[i] = count[group].first;
      if (id + 1 == count[group].second)
        dfs(count, group + 1, 0, -1, mask | (1 << i), per, ret);
      else
        dfs(count, group, id + 1, i, mask | (1 << i), per, ret);
    }
}
vector<vector<int> > permuteUnique(vector<int> &num) {
  vector<pair<int, int> > count;
  for (int i = 0; i < num.size(); i++) {
    bool flag = false;
    for (int j = 0; j < count.size(); j++)
      if (count[j].first == num[i]) {
        count[j].second++;
        flag = true;
      }
    if (!flag) count.push_back(make_pair(num[i], 1));
  }
  vector<vector<int> > ret;
  vector<int> per(num.size());
  dfs(count, 0, 0, -1, 0, per, ret);
  return ret;
}
