int ladderLength(string start, string end, unordered_set<string> &dict) {
  map<string, int> id;
  vector<string> vec;
  for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
    id.insert(make_pair(*it, id.size()));
    vec.push_back(*it);
  }
  queue<int> q;
  vector<int> f(id.size(), -1);
  vector<int> mask(id.size());
  int len = start.length();
  if (id.find(start) != id.end()) {
    f[id[start]] = 1;
    q.push(id[start]);
  } else {
    for (int i = 0; i < len; i++)
      for (int c = 0; c < 26; c++) {
        char t = start[i];
        start[i] = 'a' + c;
        if (id.find(start) != id.end()) {
          f[id[start]] = 2;
          q.push(id[start]);
          mask[id[start]] = (1 << i);
          if (start == end) return 2;
        }
        start[i] = t;
      }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    string cur = vec[u];
    for (int i = 0; i < len; i++)
      if ((mask[u] & (1 << i)) == 0)
      for (int c = 0; c < 26; c++) {
        char t = cur[i];
        cur[i] = 'a' + c;
        if (cur == end) {
          return f[u] + 1;
        }
        if (id.find(cur) != id.end()) {
          int v = id[cur];
          if (f[v] == -1) {
            f[v] = f[u] + 1;
            q.push(v);
            mask[v] = 1 << i;
          } else mask[v] |= 1 << i;
        }
        cur[i] = t;
      }
  }
  return 0;
}
