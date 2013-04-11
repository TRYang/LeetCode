#define kHashSize 297001
vector<pair<int, int> > node;
vector<int> father;
vector<int> count;
vector<int> head;
int m;
int add(int key) {
  int p = Hash(key);
  node.push_back(make_pair(key, m));
  father.push_back(m);
  count.push_back(1);
  head[p] = m++;
}
int find(int key) {
  int p = Hash(key);
  for (int i = head[p]; i != -1; i = node[i].second)
    if (node[i].first == key) return i;
  return -1;
}
int Hash(int x) {
  return (x % kHashSize + kHashSize) % kHashSize;
}
int go(int x) {
  return father[x] = father[x] == x ? x : go(father[x]);
}
int longestConsecutive(vector<int> &num) {
  if (num.size() == 0) return 0;
  m = 0;
  head.resize(kHashSize);
  fill(head.begin(), head.end(), -1);
  father.clear();
  node.clear();
  count.clear();
  int ans = 1;
  for (int i = 0; i < num.size(); i++) {
    if (find(num[i]) != -1) continue;
    int cur = m;
    add(num[i]);
    int x;
    if ((x = find(num[i] - 1)) != -1) {
      int fx = go(x);
      father[fx] = cur;
      count[cur] += count[fx];
      ans = max(ans, count[cur]);
    }
    if ((x = find(num[i] + 1)) != -1) {
      int fx = go(x);
      father[fx] = cur;
      count[cur] += count[fx];
      ans = max(ans, count[cur]);
    }
  }
  return ans;
}
