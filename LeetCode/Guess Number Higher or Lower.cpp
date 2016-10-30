// 二分答案
#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    if (n == 1) return 1;
    int l = 1, r = n;
    while (l <= r) {
      int mid = l + (r-l)/2;
      if (guess(mid) == 1) l = mid + 1;
      else if (guess(mid) == -1) r = mid - 1;
      else { l = mid; break; }
    }
    return l;
  }
};

int target = 6;
int guess(int num) {
  if (num < target) return 1;
  else if (num > target) return -1;
  return 0;
}

int main()
{
  Solution solution;
  cout << solution.guessNumber(10) << endl;
  return 0;
}
