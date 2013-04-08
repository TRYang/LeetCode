TreeNode *build(const vector<int> &num, int p, int n) {
  if (n == 0) return NULL;
  int mid = n >> 1;
  TreeNode *node = new TreeNode(num[p + mid]);
  node->left = build(num, p, mid);
  node->right = build(num, p + mid + 1, n - 1 - mid);
  return node;
}
TreeNode *sortedArrayToBST(vector<int> &num) {
  return build(num, 0, num.size());
}
