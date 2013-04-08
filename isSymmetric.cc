bool check(TreeNode *p, TreeNode *q) {
  if (!p && !q) return true;
  if (!p || !q) return false;
  if (p->val != q->val) return false;
  return check(p->left, q->right) && check(p->right, q->left);
}
bool isSymmetric(TreeNode *root) {
  if (!root) return true;
  return check(root->left, root->right);
}
