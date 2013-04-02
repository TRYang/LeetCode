void sortColors(int A[], int n) {
  int count[3];
  memset(count, 0, sizeof count);
  for (int i = 0; i < n; i++) count[A[i]]++;
  for (int i = 0, st = 0; i < 3; i++) {
    for (int j = 0; j < count[i]; j++) A[st + j] = i;
    st += count[i];
  }
}
