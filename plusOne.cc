vector<int> plusOne(vector<int> &digits) {
  vector<int> ret(digits.rbegin(), digits.rend());
  for (int i = 0; i < ret.size(); i++)
    if (ret[i] < 9) {
      ret[i]++;
      break;
    } else
    if (i + 1 == ret.size()) {
      ret[i] = 0;
      ret.push_back(1);
      break;
    } else ret[i] = 0;
  reverse(ret.begin(), ret.end());
  return ret;
}
