class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    vector<int> next_occur;
    next_occur.resize(s.length());
    int last_pos[256];
    for (int i = 0; i < 256; i++) last_pos[i] = s.length();
    for (int i = s.length() - 1; i >= 0; i--) {
      next_occur[i] = last_pos[s[i] + 128];
      last_pos[s[i] + 128] = i;
    }
    deque<int> q;
    while (!q.empty()) q.pop_back();
    int ans = 1, last = -1;
    for (int i = 0; i < s.length(); i++) {
      while (!q.empty() && next_occur[q.front()] <= i) {
        last = q.front();
        q.pop_front();
      }
      ans = max(ans, i - last);
      while (!q.empty() && next_occur[q.back()] > next_occur[i]) q.pop_back();
      q.push_back(i);
    }
    return ans;
  }
};
