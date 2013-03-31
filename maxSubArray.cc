int maxSubArray(int A[], int n) {
  if (n == 0) return 0;
  int min_sum = 0, sum = 0;
  int ans = A[0];
  for (int i = 0; i < n; i++) {
    sum += A[i];
    ans = max(ans, sum - min_sum);
    min_sum = min(min_sum, sum);
  }
  return ans;
}
