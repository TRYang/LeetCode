void find(TreeNode *root, int sum, vector<int> &cur, vector<vector<int> > &ret) {
  if (!root->left && !root->right) {
    if (sum == root->val) {
      cur.push_back(root->val);
      ret.push_back(cur);
      cur.pop_back();
    }
    return;
  }
  cur.push_back(root->val);
  if (root->left) find(root->left, sum - root->val, cur, ret);
  if (root->right) find(root->right, sum - root->val, cur, ret);
  cur.pop_back();
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
  vector<vector<int> > ret;
  if (!root) return ret;
  vector<int> cur;
  find(root, sum, cur, ret);
}
