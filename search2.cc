bool search(int A[], int n, int target) {
  if (n == 0) return false;
  if (A[0] == A[n - 1]) {
    for (int i = 0; i < n; i++)
      if (A[i] == target) return true;
    return false;
  } else {
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (A[mid] == target) return true;
      if (A[mid] >= A[0]) {
        if (target >= A[0]) {
          if (target > A[mid]) left = mid + 1;
          else right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (target < A[0]) {
          if (target > A[mid]) left = mid + 1;
          else right = mid - 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return false;
  }
}
