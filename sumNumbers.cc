int find(TreeNode *root, int cur) {
  if (!root->left && !root->right) return cur * 10 + root->val;
  int ret = 0;
  if (root->left) ret += find(root->left, cur * 10 + root->val);
  if (root->right) ret += find(root->right, cur * 10 + root->val);
  return ret;
}
int sumNumbers(TreeNode *root) {
  if (!root) return 0;
  return find(root, 0);
}
