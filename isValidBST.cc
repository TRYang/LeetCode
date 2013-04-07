pair<int, int> find(TreeNode *root) {
  if (!root->left && !root->right) return make_pair(root->val, root->val);
  pair<int, int> ret = make_pair(root->val, root->val);
  if (root->left) {
    pair<int, int> left = find(root->left);
    if (left.first > left.second || left.second >= root->val) return make_pair(1, 0);
    ret.first = left.first;
  }
  if (root->right) {
    pair<int, int> right = find(root->right);
    if (right.first > right.second || right.first <= root->val) return make_pair(1, 0);
    ret.second = right.second;
  }
  return ret;
}
bool isValidBST(TreeNode *root) {
  if (!root || (!root->left && !root->right)) return true;
  pair<int, int> pii = find(root);
  return pii.first <= pii.second;
}
