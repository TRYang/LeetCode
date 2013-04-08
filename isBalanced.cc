bool check(TreeNode *root, int &dep) {
  if (!root) {
    dep = 0;
    return true;
  }
  dep = 1;
  int left_dep = 0, right_dep = 0;
  if (root->left)
    if (!check(root->left, left_dep)) return false;
  if (root->right)
    if (!check(root->right, right_dep)) return false;
  if (left_dep - right_dep > 1 || right_dep - left_dep > 1) return false;
  dep += max(left_dep, right_dep);
  return true;
}
bool isBalanced(TreeNode *root) {
  if (!root) return true;
  int dep;
  return check(root, dep);
}
