void flatten(TreeNode *&last, TreeNode *cur) {
  if (!cur) return;
  TreeNode *lc = cur->left;
  TreeNode *rc = cur->right;
  cur->left = cur->right = NULL;
  last->right = cur;
  last = cur;
  if (lc) flatten(last, lc);
  if (rc) flatten(last, rc);
}
void flatten(TreeNode *root) {
  if (!root) return;
  TreeNode *super_root = new TreeNode(0);
  flatten(super_root, root);
}
