string minWindow(string S, string T) {
  if (T == "") return "";
  map<char, int> count;
  for (int i = 0; i < T.length(); i++) count[T[i]]++;
  pair<int, int> ans(-1, -1);
  for (int i = 0, last = -1, cnt = 0; i < S.length(); i++) {
    if (count.find(S[i]) != count.end()) {
      count[S[i]]--;
      if (count[S[i]] == 0) ++cnt;
    }
    while (last < i - 1) {
      ++last;
      if (count.find(S[last]) != count.end()) {
        if (count[S[last]] >= 0) {
          --last;
          break;
        }
        count[S[last]]++;
      }
    }
    if (cnt == count.size()) 
      if (ans.first == -1 || i - last < ans.second)
        ans = make_pair(last + 1, i - last);
  }
  if (ans.first == -1) return "";
  return S.substr(ans.first, ans.second);
}
