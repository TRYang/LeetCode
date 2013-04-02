int sqrt(int x) {
  if (x == 0) return 0;
  int left = 1, right = x;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (x / mid <= mid) {
      if (mid * mid == x) return mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  if (x / left == left) return left; else return right;
}
