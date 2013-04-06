int largestRectangleArea(vector<int> &height) {
  stack<int> stk;
  vector<int> left;
  for (int i = 0; i < height.size(); i++) {
    while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
    if (stk.empty()) left.push_back(-1);
    else left.push_back(stk.top());
    stk.push(i);
  }
  while (!stk.empty()) stk.pop();
  int ans = 0;
  for (int i = height.size() - 1; i >= 0; i--) {
    while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
    int right;
    if (stk.empty()) right = height.size();
    else right = stk.top();
    stk.push(i);
    ans = max(ans, height[i] * (right - left[i] - 1));
  }
  return ans;
}
