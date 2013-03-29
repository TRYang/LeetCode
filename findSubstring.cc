#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::map;

const static int kBASE = 39;
unsigned long long hash(const string &s, int st, int en) {
  unsigned long long ret =0;
  for (int i = st; i < en; i++) ret = ret * kBASE + s[i];
  return ret;
}
vector<int> findSubstring(string S, vector<string> &L) {
  if (S == "" || L.size() == 0) return vector<int>(0);
  int len = L[0].length();
  vector<int> ret(0);

  int m = 0;
  map<unsigned long long, int> id;
  vector<int> count(0);
  id.clear();
  for (int i = 0; i < L.size(); i++) {
    unsigned long long temp = hash(L[i], 0, len);
    if (id.find(temp) == id.end()) {
      id[temp] = m++;
      count.push_back(1);
    } else count[id[temp]]++;
  }

  vector<unsigned long long> hash_value(S.length() + 1);
  vector<unsigned long long> POW(S.length() + 1);
  hash_value[0] = 0;
  for (int i = 1; i <= S.length(); i++) hash_value[i] = hash_value[i - 1] * kBASE + S[i - 1];
  POW[0] = 1;
  for (int i = 1; i <= S.length(); i++) POW[i] = POW[i - 1] * kBASE;

  for (int offset = 0; offset < len; offset++) {
    vector<int> num(0);
    for (int i = offset; i + len <= S.length(); i += len) {
      unsigned long long value = hash_value[i + len] - hash_value[i] * POW[len];
      if (id.find(value) != id.end()) num.push_back(id[value]);
      else num.push_back(-1);
    }
    if (num.size() < L.size()) continue;
    vector<int> sum(m);
    int cnt = 0;
    for (int i = 0; i < L.size() - 1; i++)
      if (num[i] > -1) {
        sum[num[i]]++;
        if (sum[num[i]] == count[num[i]]) ++cnt;
      }
    for (int i = 0; i + L.size() <= num.size(); i++) {
      int ptr = i + L.size() - 1;
      if (num[ptr] > -1) {
        sum[num[ptr]]++;
        if (sum[num[ptr]] == count[num[ptr]]) ++cnt;
      }
      if (cnt == m) ret.push_back(i * len + offset);
      if (num[i] > -1) {
        if (sum[num[i]] == count[num[i]]) --cnt;
        sum[num[i]]--;
      }
    }
  }
  return ret;
}

int main() {
  string s = "barfoothefoobarman";
  vector<string> a(0);
  a.push_back("foo");
  a.push_back("bar");
  vector<int> b = findSubstring(s, a);
  return 0;
}
