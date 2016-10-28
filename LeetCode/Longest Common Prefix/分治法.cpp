// 分治法
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<string>::iterator VecStrIter;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string str = divide(strs.begin(), strs.end());
    return str;
  }
private:
  string divide(VecStrIter lower, VecStrIter upper) {
    if (lower == upper - 1) return *lower;

    int dis = upper - lower;
    int mid = dis / 2;
    VecStrIter middle = lower + mid;

    string left_common_prefix = divide(lower, middle);
    string right_common_prefix = divide(middle, upper);
    string s = common_prefix(left_common_prefix, right_common_prefix);

    return s;
  }
private:
  string common_prefix(string &left, string &right) {
    if (left == "" || right == "") return "";
    auto p1 = left.begin(), p2 = right.begin();
    while (p1 != left.end() && p2 != right.end() && *p1 == *p2) {
      p1++;
      p2++;
    }
    string s(left.begin(), p1);
    return s;
  }
};

std::ostream& operator<<(std::ostream &stream, vector<string> &strs) {
  for (auto it = strs.begin(); it != strs.end(); ++it) {
    stream << *it << endl;
  }
  return stream;
}

int main()
{
//  vector<string> strs = {
//    "hello",
//    "hello world",
//    "hell",
//    "heal"
//  };
  vector<string> strs = {
    "cbc",
    "ca"
  };
//  vector<string> strs = {
//    "hello",
//    "hello world"
//  };
//  string s1("c");
//  string s2("c");
//  cout << common_prefix(s1, s2) << endl;

  Solution solution;
  cout << solution.longestCommonPrefix(strs) << endl;
  return 0;
}
