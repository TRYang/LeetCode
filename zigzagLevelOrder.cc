vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  vector<vector<int> > ret;
  if (!root) return ret;
  vector<TreeNode*> que;
  que.push_back(root);
  int level = 0;
  while (que.size() > 0) {
    vector<TreeNode*> nxt;
    vector<int> val;
    for (int i = 0; i < que.size(); i++) {
      TreeNode *node = que[i];
      val.push_back(node->val);
      if (node->left) nxt.push_back(node->left);
      if (node->right) nxt.push_back(node->right);
    }
    if (level) val = vector<int>(val.rbegin(), val.rend());
    level = 1 - level;
    ret.push_back(val);
    que = nxt;
  }
  return ret;
}
