class Solution {
public:
  string get(int p, int bit) {
    string str = "IVXLCDM";
    if (bit == 0) return "";
    char single = str[p << 1];
    if (bit <= 3) return string(bit, single);
    char five = str[(p << 1) + 1];
    if (bit == 4) return string(1, single) + string(1, five);
    if (bit <= 8) return string(1, five) + string(bit - 5, single);
    char ten = str[(p << 1) + 2];
    if (bit == 9) return string(1, single) + string(1, ten);
    return string(1, ten);
  }
  string intToRoman(int num) {
    string ret;
    int p = 0;
    while (num) {
      ret = get(p, num % 10) + ret;
      ++p;
      num /= 10;
    }
    return ret;
  }
};
