class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    double ans;
    if ((n + m) % 2 == 0) {
      ans = findK(A, m, B, n, (n + m) / 2);
      ans += findK(A, m, B, n, (n + m) / 2 + 1);
      ans /= 2;
    } else {
      ans = findK(A, m, B, n, (n + m) / 2 + 1);
    }
    return ans;
  }

  double findK(int A[], int m, int B[], int n, int k) {
    int a_left = 0, a_right = m - 1;
    int b_left = 0, b_right = n - 1;
    int a_ans = -1, b_ans = -1, tot = -1;
    while (a_left <= a_right) {
      int a_mid = a_left + (a_right - a_left) / 2;
      int b_pos = binary_search(B, b_left, b_right, A[a_mid]);
      if (a_mid + b_pos + 2 >= k) {
        a_ans = a_mid;
        b_ans = b_pos;
        tot = a_mid + b_pos + 2;
        a_right = a_mid - 1;
        b_right = b_pos;
      } else {
        a_left = a_mid + 1;
        b_left = max(b_pos, 0);
      }
    }
    if (tot == k) return A[a_ans];
    if (a_ans != -1 && b_ans != -1 && A[a_ans] == B[b_ans]) return A[a_ans];
    return findK(B, n, A, m, k);
  }

  int binary_search(int B[], int left, int right, int target) {
    int ret = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (B[mid] <= target) {
        ret = mid;
        left = mid + 1;
      } else right = mid - 1;
    }
    return ret;
  }
};
