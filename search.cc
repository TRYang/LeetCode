int search(int A[], int n, int target) {
  if (n == 0) return -1;
  if (target >= A[0]) {
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (A[mid] == target) return mid;
      if (A[mid] < A[0] || A[mid] > target) right = mid - 1; else left = mid + 1;
    }
  } else {
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (A[mid] == target) return mid;
      if (A[mid] >= A[0] || A[mid] < target) left = mid + 1; else right = mid - 1;
    }
  }
  return -1;
}
