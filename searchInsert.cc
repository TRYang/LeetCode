int searchInsert(int A[], int n, int target) {
  if (n == 0) return 0;
  int left = 0, right = n - 1;
  int ret = n;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (A[mid] == target) return mid;
    if (A[mid] > target) {
      ret = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return ret;
}
