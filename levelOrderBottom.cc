vector<vector<int> > levelOrderBottom(TreeNode *root) {
  vector<vector<int> > ret;
  if (!root) return ret;
  vector<TreeNode*> que;
  que.push_back(root);
  while (que.size() > 0) {
    vector<TreeNode*> nxt;
    vector<int> val;
    for (int i = 0; i < que.size(); i++) {
      TreeNode *node = que[i];
      val.push_back(node->val);
      if (node->left) nxt.push_back(node->left);
      if (node->right) nxt.push_back(node->right);
    }
    ret.push_back(val);
    que = nxt;
  }
  ret = vector<vector<int> >(ret.rbegin(), ret.rend());
  return ret;
}
