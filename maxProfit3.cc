int maxProfit(vector<int> &prices) {
  int ans = 0;
  int first_use, flag1 = 0;
  int first_profit = 0;
  int second_use, flag2 = 0;
  for (int i = 0; i < prices.size(); i++) {
    if (flag2) ans = max(ans, second_use + prices[i]);
    if (!flag2 || first_profit - prices[i] > second_use) {
      second_use = first_profit - prices[i];
      flag2 = 1;
    }
    if (flag1) first_profit = max(first_profit, first_use + prices[i]);
    if (!flag1 || -prices[i] > first_use) {
      first_use = -prices[i];
      flag1 = true;
    }
  }
  return ans;
}
