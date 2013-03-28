void update(int &ref, int value, int target) {
  if (abs(ref - target) > abs(value - target)) ref = value;
}
int threeSumClosest(vector<int> &num, int target) {
  vector<int> vec(num);
  sort(vec.begin(), vec.end());
  int n = vec.size();
  if (n < 3) return target;
  int ans = vec[0] + vec[1] + vec[2];
  for (int i = 0; i < n; i++) {
    int ptr = n - 1;
    for (int j = 0; j < i && ptr > i; j++) {
      while (ptr > i + 1 && vec[j] + vec[i] + vec[ptr - 1] >= target) --ptr;
      update(ans, vec[j] + vec[i] + vec[ptr], target);
      if (ptr > i + 1) update(ans, vec[j] + vec[i] + vec[ptr - 1], target);
    }
  }
  return ans;
}
