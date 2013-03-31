vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
  vector<Interval> ret(intervals);
  if (intervals.size() == 0) {
    ret.push_back(newInterval);
    return ret;
  }
  for (vector<Interval>::iterator it = ret.begin(); it != ret.end(); ) {
    if (it->start > newInterval.end || it->end < newInterval.start) {
      it++;
      continue;
    }
    newInterval.start = min(newInterval.start, it->start);
    newInterval.end = max(newInterval.end, it->end);
    ret.erase(it);
  }

  vector<Interval>::iterator it = ret.begin();
  while (it != ret.end() && it->start < newInterval.end) it++;
  ret.insert(it, newInterval);
  return ret;
}
