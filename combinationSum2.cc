void dfs(vector<int> &elements, int dep, int sum, int target, vector<int> &path, vector<vector<int> > &ret) {
  if (sum == target) {
    ret.push_back(path);
    return;
  }
  if (dep >= elements.size()) return;
  if (sum + elements[dep] > target) return;
  int j = dep;
  while (j < elements.size() && elements[j] == elements[dep]) j++;
  for (int i = dep; i < j; i++) {
    path.push_back(elements[i]);
    dfs(elements, j, sum + (i - dep + 1) * elements[dep], target, path, ret);
  }
  for (int i = dep; i < j; i++) path.pop_back();
  dfs(elements, j, sum, target, path, ret);
}
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int> > ret;
  ret.clear();
  vector<int> path(0);
  dfs(candidates, 0, 0, target, path, ret);
  return ret;
}
