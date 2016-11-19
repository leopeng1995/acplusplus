// 双指针（头部和尾部）
// i: 0-n/2
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
  bool isPalindrome(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = prev(s.end());
    while (left < right) {
      if (!::isalnum(*left)) ++left;
      else if (!::isalnum(*right)) --right;
      else if (*left != *right) return false;
      else { left++, right--; }
    }
    return true;
  }
};

int main()
{
  string s1("A man, a plan, a canal: Panama");
  string s2("race a car");

  Solution solution;
  cout << solution.isPalindrome(s1) << endl;
  cout << solution.isPalindrome(s2) << endl;
  return 0;
}