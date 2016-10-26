// 栈的使用
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool isValid(string &s) {
    if (s.empty()) return true;
    static unordered_set<char> left({'(', '[', '{'});
    static unordered_set<char> right({')', ']', '}'});
    static unordered_map<char, char> mapping;
    mapping[')'] = '(';
    mapping[']'] = '[';
    mapping['}'] = '{';

    stack<char> checkStack;
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (right.find(*it) != right.end()) {
        if (checkStack.empty()) return false;
        if (checkStack.top() != mapping[*it]) return false;
        checkStack.pop();
      } else {
        checkStack.push(*it);
      }
    }
    if (checkStack.empty()) return true;
    return false;
  }
};

int main()
{
  string s1("()");
  string s2("()[]{}");
  string s3("(]");
  string s4("([)]");
  string s5("([{}])");
  string s6("");
  Solution solution;
  cout << solution.isValid(s1) << endl;
  cout << solution.isValid(s2) << endl;
  cout << solution.isValid(s3) << endl;
  cout << solution.isValid(s4) << endl;
  cout << solution.isValid(s5) << endl;
  cout << solution.isValid(s6) << endl;
  return 0;
}
