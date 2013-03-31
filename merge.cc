bool cmp(const Interval &a, const Interval &b) {
  return a.start < b.start || (a.start == b.start && a.end > b.end);
}
vector<Interval> merge(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end(), cmp);
  vector<Interval> ret;
  if (intervals.size() == 0) return ret;
  int n = 1;
  for (int i = 1, bound = intervals[0].end; i < intervals.size(); i++)
    if (intervals[i].end > bound) {
      intervals[n++] = intervals[i];
      bound = intervals[i].end;
    }
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && intervals[j].start <= intervals[j - 1].end; j++);
    ret.push_back(Interval(intervals[i].start, intervals[j - 1].end));
  }
  return ret;
}
