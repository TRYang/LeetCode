static const int kBASE = 127;
vector<string> anagrams(vector<string> &strs) {
  vector<string> ret;
  if (strs.size() == 0) return ret;
  vector<pair<unsigned long long, int> > hash_value(strs.size());
  for (int i = 0; i < strs.size(); i++) {
    hash_value[i].first = 0;
    hash_value[i].second = i;
    vector<int> count(26);
    for (int j = 0; j < strs[i].length(); j++) count[strs[i][j] - 'a']++;
    for (int j = 0; j < 26; j++) hash_value[i].first = hash_value[i].first * kBASE + count[j] + j;
  }
  sort(hash_value.begin(), hash_value.end());
  for (int i = 0, j; i < hash_value.size(); i = j) {
    for (j = i + 1; j < hash_value.size() && hash_value[j].first == hash_value[i].first; j++);
    if (j == i + 1) continue;
    for (int k = i; k < j; k++) ret.push_back(strs[hash_value[k].second]);
  }
  return ret;
}
