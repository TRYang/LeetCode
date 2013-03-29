void dfs(vector<int> &elements, int dep, int sum, int target, vector<int> &path, vector<vector<int> > &ret) {
  if (dep >= elements.size()) return;
  if (sum == target) {
    ret.push_back(path);
    return;
  }
  if (sum + elements[dep] > target) return;
  path.push_back(elements[dep]);
  dfs(elements, dep, sum + elements[dep], target, path, ret);
  path.pop_back();
  dfs(elements, dep + 1, sum, target, path, ret);
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());
  candidates.end() = unique(candidates.begin(), candidates.end());
  vector<vector<int> > ret;
  ret.clear();
  vector<int> path(0);
  dfs(candidates, 0, 0, target, path, ret);
  return ret;
}
