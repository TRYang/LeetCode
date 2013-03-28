int maxArea(vector<int> &height) {
  int n = height.size();
  vector<int> next(n);
  vector<int> prev(n);

  for (int i = 0; i < n; i++) next[i] = n;
  int last = 0;
  for (int i = 1; i < n; i++)
    if (height[i] > height[last]) {
      next[last] = i;
      last = i;
    }
  
  for (int i = 0; i < n; i++) prev[i] = -1;
  last = n - 1;
  for (int i = n - 2; i >= 0; i--)
    if (height[i] > height[last]) {
      prev[last] = i;
      last = i;
    }

  //all equal
  if (next[0] == n && prev[n - 1] == -1) return (n - 1) * height[0];
  int ans = 0;
  for (int left = 0, right = n - 1; left < n; left = next[left]) {
    while (right > -1 && height[left] > height[right]) right = prev[right];
    if (right == -1) break;
    ans = max(ans, (right - left) * height[left]);
  }
  for (int right = n - 1, left = 0; right > -1; right = prev[right]) {
    while (left < n && height[right] > height[left]) left = next[left];
    if (left == n) break;
    ans = max(ans, (right - left) * height[right]);
  }
  return ans;
}
