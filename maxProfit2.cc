int maxProfit(vector<int> &prices) {
  int ans = 0, max_profit;
  bool flag = false;
  for (int i = 0; i < prices.size(); i++) {
    int temp = ans;
    if (flag) ans = max(ans, max_profit + prices[i]);
    if (!flag || temp - prices[i] > max_profit) {
      max_profit = temp - prices[i];
      flag = true;
    }
  }
  return ans;
}
