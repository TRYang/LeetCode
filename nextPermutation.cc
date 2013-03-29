void nextPermutation(vector<int> &num) {
  int max_v = 0;
  int pos = -1;
  for (int i = num.size() - 1; i >= 0; i--) {
    if (max_v > num[i]) {
      pos = i;
      break;
    }
    max_v = num[i];
  }
  if (pos == -1) {
    sort(num.begin(), num.end());
    return;
  }
  int p = -1;
  for (int i = pos + 1; i < num.size(); i++)
    if (num[i] > num[pos])
      if (p == -1 || num[i] < num[p]) p = i;
  swap(num[pos], num[p]);
  vector<int>::iterator it = num.end();
  for (int i = num.size() - 1; i != pos; i--) it--;
  sort(it, num.end());
}
