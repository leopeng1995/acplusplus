// 逆波兰表达式
// https://en.wikipedia.org/wiki/Reverse_Polish_notation
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    if (tokens.empty()) return 0;
    static unordered_set<string> operators({"+", "-", "*", "/"});

    stack<int> s;
    for (auto it = tokens.begin(); it != tokens.end(); it++) {
      if (operators.find(*it) != operators.end()) {
        int val2 = s.top(); s.pop();
        int val1 = s.top(); s.pop();
        if (*it == "+") {
          s.push(val1 + val2);
        } else if (*it == "-") {
          s.push(val1 - val2);
        } else if (*it == "*") {
          s.push(val1 * val2);
        } else if (*it == "/") {
          s.push(val1 / val2);
        }
      } else {
        int val = stol(*it);
        s.push(val);
      }
    }
    return s.top();
  }
};

int main()
{
  vector<string> token1({"2", "1", "+", "3", "*"});
  vector<string> token2({"4", "13", "5", "/", "+"});

  Solution solution;
  cout << solution.evalRPN(token1) << endl;
  cout << solution.evalRPN(token2) << endl;
  return 0;
}
