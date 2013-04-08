TreeNode *build(const vector<int> &preorder, int sp, const vector<int> &inorder, int tp, int n) {
  if (n == 0) return NULL;
  TreeNode *cur = new TreeNode(preorder[sp]);
  int p = tp;
  while (inorder[p] != preorder[sp]) ++p;
  int ln = p - tp, rn = n - 1 - ln;
  cur->left = build(preorder, sp + 1, inorder, tp, ln);
  cur->right = build(preorder, sp + 1 + ln, inorder, tp + 1 + ln, rn);
  return cur;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  return build(preorder, 0, inorder, 0, preorder.size());
}
