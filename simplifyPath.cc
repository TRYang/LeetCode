string simplifyPath(string path) {
  stack<string> stk;
  int start = 0;
  if (path[0] == '/') stk.push(""); else {
    start = path.find('/');
    if (start == string::npos) return path;
    stk.push(path.substr(0, start));
  }
  while (start + 1 < path.length()) {
    int next = path.find('/', start + 1);
    if (next == string::npos) next = path.length();
    if (next == start + 1) {
      start = next;
      continue;
    }
    if (next - start == 2 && path[start + 1] == '.') {
      start = next;
      continue;
    }
    if (next - start == 3 && path[start + 1] == '.' && path[start + 2] == '.') {
      if (stk.size() > 1 && stk.top() != "..") stk.pop();
      else {
        if (stk.size() > 1 || stk.top() != "") stk.push("..");
      }
      start = next;
      continue;
    }
    stk.push(path.substr(start + 1, next - start - 1));
    start = next;
  }
  string ret = stk.top();
  stk.pop();
  while (!stk.empty()) {
    ret = stk.top() + "/" + ret;
    stk.pop();
  }
  if (ret == "") ret = "/";
  return ret;
}
