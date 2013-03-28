bool isValid(string s) {
  string brackets = "()[]{}";
  stack<int> st;
  while (!st.empty()) st.pop();
  for (int i = 0; i < s.length(); i++) {
    if (brackets.find(s[i]) % 2 == 0) {
      st.push(brackets.find(s[i]) / 2);
    } else {
      if (st.empty() || brackets.find(s[i]) / 2 != st.top()) return false;
      st.pop();
    }
  }
  return st.empty();
}
