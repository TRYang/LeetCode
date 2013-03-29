char *strStr(char *haystack, char *needle) {
  int n = strlen(haystack), m = strlen(needle);
  if (m == 0) return haystack;
  vector<int> next(m);
  next[0] = -1;
  for (int i = 1, j = -1; i < m; i++) {
    while (j > -1 && *(needle + 1 + j) != *(needle + i)) j = next[j];
    if (*(needle + 1 + j) == *(needle + i)) ++j;
    next[i] = j;
  }
  for (int i = 0, j = -1; i < n; i++) {
    while (j > -1 && *(needle + 1 + j) != *(haystack + i)) j = next[j];
    if (*(needle + 1 + j) == *(haystack + i)) ++j;
    if (j == m - 1) return haystack + (i - j);
  }
  return NULL;
}
