vector<string> fullJustify(vector<string> &word, int L) {
  vector<string> ret;
  for (int i = 0, j; i < word.size(); i = j) {
    int tot_len = word[i].length(), word_tot_len = tot_len;
    for (j = i + 1; j < word.size(); j++) {
      if (tot_len + 1 + word[j].length() > L) break;
      tot_len += 1 + word[j].length();
      word_tot_len += word[j].length();
    }
    int tot_space = L - word_tot_len;
    string line(word[i]);
    for (int k = i + 1; k < j; k++) {
      int c = (tot_space - 1) / (j - k) + 1;
      if (j == word.size()) c = 1;
      tot_space -= c;
      line += string(c, ' ');
      line += word[k];
    }
    if (line.length() < L) line += string(L - line.length(), ' ');
    ret.push_back(line);
  }
  return ret;
}
