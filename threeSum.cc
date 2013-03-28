vector<vector<int> > threeSum(vector<int> &num) {
  int n = num.size();
  map<int, vector<pair<int, int> > > dict;
  dict.clear();
  set<pair<int, pair<int, int> > > ans;
  ans.clear();
  for (int i = 0; i < n; i++) {
    if (dict.find(-num[i]) != dict.end()) {
      for (vector<pair<int, int> >::iterator it = dict[-num[i]].begin(); it != dict[-num[i]].end(); it++) {
        pair<int, pair<int, int> > tmp;
        tmp.first = num[i];
        tmp.second = *it;
        if (tmp.first > tmp.second.first) swap(tmp.first, tmp.second.first);
        if (tmp.first > tmp.second.second) swap(tmp.first, tmp.second.second);
        if (tmp.second.first > tmp.second.second) swap(tmp.second.first, tmp.second.second);
        ans.insert(tmp);
      }
    }
    for (int j = 0; j < i; j++) {
      if (dict.find(num[j] + num[i]) == dict.end()) {
        dict.insert(make_pair(num[j] + num[i], vector<pair<int, int> >(0)));
      }
      dict[num[j] + num[i]].push_back(make_pair(num[j], num[i]));
    }
  }
  vector<vector<int> > ret;
  ret.clear();
  for (set<pair<int, pair<int, int> > >::iterator it = ans.begin(); it != ans.end(); it++) {
    vector<int> tmp(3);
    tmp[0] = it->first;
    tmp[1] = it->second.first;
    tmp[2] = it->second.second;
    ret.push_back(tmp);
  }
  return ret;
}
