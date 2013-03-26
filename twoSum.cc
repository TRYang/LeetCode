class Solution {
public:
  vector<int> twoSum(vector<int> &number, int target) {
    std::map<int, int> dict;
    dict.clear();
    for (int i = 0; i < number.size(); i++) dict[number[i]] = i;
    for (int i = 0; i < number.size(); i++)
      if (dict.find(target - number[i]) != dict.end()) {
        vector<int> res;
        res.clear();
        res.push_back(i + 1);
        res.push_back(dict[target - number[i]] + 1);
        return res;
      }
    return vector<int>(-1, 2);
  }
};
