bool canJump(int A[], int n) {
  int last = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (i + A[i] >= last) last = i;
  }
  return last == 0;
}
