#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long r = 0;
    long long t = x;
    t = t > 0 ? t : -t;

    for (; t; t /= 10)
      r = r * 10 + t % 10;

    bool sign = x > 0 ? false : true;
    if (r > 2147483647 || (sign && r > 2147483648)) {
      return 0;
    } else {
      if (sign) return -r;
      else return r;
    }
  }
};

int main()
{
  Solution solution;
  cout << solution.reverse(0) << endl;
  cout << solution.reverse(123) << endl;
  cout << solution.reverse(-123) << endl;
  return 0;
}