pair<int, int> dfs(TreeNode *root) {
  if (!root->left && !root->right) return make_pair(root->val, max(0, root->val));
  int down = 0;
  int sum = root->val;
  int best = root->val;
  if (root->left) {
    pair<int, int> temp = dfs(root->left);
    best = max(best, temp.first);
    sum += temp.second;
    down = max(down, root->val + temp.second);
  }
  if (root->right) {
    pair<int, int> temp = dfs(root->right);
    best = max(best, temp.first);
    sum += temp.second;
    down = max(down, root->val + temp.second);
  }
  best = max(best, sum);
  return make_pair(best, down);
}
int maxPathSum(TreeNode *root) {
  if (!root) return 0;
  pair<int, int> ans = dfs(root);
  return ans.first;
}
