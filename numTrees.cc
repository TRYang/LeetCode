int numTrees(int n) {
  if (n <= 1) return 1;
  int ret = 0;
  for (int i = 0; i < n; i++) ret += numTrees(i) * numTrees(n - 1 - i);
  return ret;
}
