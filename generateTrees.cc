vector<TreeNode *> generateTrees(int n, int offset) {
  if (n == 0) {
    vector<TreeNode*> ret;
    ret.push_back(NULL);
    return ret;
  }
  if (n == 1) {
    vector<TreeNode*> ret;
    ret.push_back(new TreeNode(offset));
    return ret;
  }
  vector<TreeNode*> ret;
  for (int i = 0; i < n; i++) {
    vector<TreeNode*> left_subtree = generateTrees(i, offset);
    vector<TreeNode*> right_subtree = generateTrees(n - 1 - i, offset + i + 1);
    for (int j = 0; j < left_subtree.size(); j++)
      for (int k = 0; k < right_subtree.size(); k++) {
        TreeNode *root = new TreeNode(offset + i);
        root->left = left_subtree[j];
        root->right = right_subtree[k];
        ret.push_back(root);
      }
  }
  return ret;
}
vector<TreeNode *> generateTrees(int n) {
  return generateTrees(n, 1);
}
