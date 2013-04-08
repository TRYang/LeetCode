void dfs(TreeLinkNode *root, TreeLinkNode *last) {
  if (last) last->next = root;
  if (root->left) {
    if (last) dfs(root->left, last->right); else dfs(root->left, last);
    dfs(root->right, root->left);
  }
}
void connect(TreeLinkNode *root) {
  if (!root) return;
  TreeLinkNode *last = NULL;
  dfs(root, last);
}
