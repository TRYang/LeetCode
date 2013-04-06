vector<vector<int> > fourSum(vector<int> &num, int target) {
  int N = num.size();
  sort(num.begin(), num.end());
  map<int, vector<int> > dict;
  set<vector<int> > ans;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int need = target - num[i] - num[j];
      if (dict.find(need) != dict.end()) {
        for (vector<int>::iterator it = dict[need].begin(); it != dict[need].end(); it++) {
          vector<int> temp;
          temp.push_back(*it);
          temp.push_back(need - *it);
          temp.push_back(num[i]);
          temp.push_back(num[j]);
          ans.insert(temp);
        }
      }
    }
    for (int j = 0; j < i; j++) dict[num[i] + num[j]].push_back(num[j]);
  }
  vector<vector<int> > ret;
  for (set<vector<int> >::iterator it = ans.begin(); it != ans.end(); it++) ret.push_back(*it);
  return ret;
}
