void find(TreeNode *root, TreeNode *&p, TreeNode *&q, TreeNode *&last) {
  if (root->left) find(root->left, p, q, last);
  if (last) {
    if (last->val > root->val) {
      if (!p) p = last, q = root;
      else q = root;
    }
  }
  last = root;
  if (root->right) find(root->right, p, q, last);
}
void recoverTree(TreeNode *root) {
  TreeNode *p = NULL, *q = NULL, *last = NULL;
  if (!root) return;
  find(root, p, q, last);
  if (p && q) swap(p->val, q->val);
}
