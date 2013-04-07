vector<int> inorderTraversal(TreeNode *root) {
  stack<TreeNode*> stk;
  stk.push(root);
  vector<int> ret;
  if (!root) return ret;
  while (!stk.empty()) {
    TreeNode *cur = stk.top();
    if (!cur->left) {
      stk.pop();
      ret.push_back(cur->val);
      if (cur->right) stk.push(cur->right);
    } else {
      stk.push(cur->left);
      cur->left = NULL;
    }
  }
  return ret;
}
