void dfs(TreeLinkNode *root, TreeLinkNode *last) {
  if (last) root->next = last;
  TreeLinkNode *next_last = NULL;
  while (last && !last->left && !last->right) last = last->next;
  if (last) 
    if (last->left) next_last = last->left; else next_last = last->right;
  if (root->right) {
    dfs(root->right, next_last);
    next_last = root->right;
  }
  if (root->left) dfs(root->left, next_last);
}
void connect(TreeLinkNode *root) {
  if (!root) return;
  dfs(root, NULL);
}
