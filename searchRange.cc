vector<int> searchRange(int A[], int n, int target) {
  int left_bound = -1, right_bound = -1;
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (A[mid] == target) {
      left_bound = mid;
      right = mid - 1;
      continue;
    }
    if (A[mid] < target) left = mid + 1; else right = mid - 1;
  }
  left = 0, right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (A[mid] == target) {
      right_bound = mid;
      left = mid + 1;
      continue;
    }
    if (A[mid] < target) left = mid + 1; else right = mid - 1;
  }
  vector<int> res(0);
  res.push_back(left_bound);
  res.push_back(right_bound);
  return res;
}
