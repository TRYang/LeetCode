TreeNode *build(const vector<int> &inorder, int sp, const vector<int> &postorder, int tp, int n) {
  if (n == 0) return NULL;
  int p = sp;
  while (inorder[p] != postorder[tp + n - 1]) p++;
  int ln = p - sp, rn = n - 1 - ln;
  TreeNode *cur = new TreeNode(postorder[tp + n - 1]);
  cur->left = build(inorder, sp, postorder, tp, ln);
  cur->right = build(inorder, sp + 1 + ln, postorder, tp + ln, rn);
  return cur;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  return build(inorder, 0, postorder, 0, inorder.size());
}
