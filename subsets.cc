void find_subsets(int dep, vector<int> &S, vector<int> &curS, vector<vector<int> > &ret) {
  if (dep == S.size()) {
    ret.push_back(curS);
    return;
  }
  int next = dep + 1;
  while (next < S.size() && S[next] == S[dep]) ++next;
  find_subsets(next, S, curS, ret);
  for (int i = dep; i < next; i++) {
    curS.push_back(S[i]);
    find_subsets(next, S, curS, ret);
  }
  while (curS.size() > 0 && curS.back() == S[dep]) curS.pop_back();
}
vector<vector<int> > subsets(vector<int> &S) {
  vector<vector<int> > ret;
  sort(S.begin(), S.end());
  vector<int> curS;
  find_subsets(0, S, curS, ret);
  return ret;
}
