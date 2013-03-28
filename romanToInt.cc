int get_num(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
  }
}
int romanToInt(string s) {
  string pattern = "IVXLCDM";
  int ret = 0;
  for (int i = 0; i < s.length(); ) {
    if (i + 1 == s.length()) {
      ret += get_num(s[i]);
      break;
    }
    if (pattern.find(s[i]) < pattern.find(s[i + 1])) {
      ret += get_num(s[i + 1]) - get_num(s[i]);
      i += 2;
      continue;
    }
    ret += get_num(s[i]);
    i++;
  }
  return ret;
}
