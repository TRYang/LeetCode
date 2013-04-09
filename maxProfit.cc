int maxProfit(vector<int> &prices) {
  int ans = 0, min_price = -1;
  for (int i = 0; i < prices.size(); i++) {
    if (min_price >= 0) ans = max(ans, prices[i] - min_price);
    if (min_price == -1 || prices[i] < min_price) min_price = prices[i];
  }
  return ans;
}
