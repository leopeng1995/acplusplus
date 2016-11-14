#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums.empty()) return 0;

    int sum = 0;
    for (auto it = nums.begin(); it != nums.end(); it++)
      sum += *it;

    int n = nums.size();
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= nums[i - 1])
          dp[i][j] |= dp[i - 1][j - nums[i - 1]];
      }
    }

    int diff = INT_MAX;
    for (int j = sum/2; j >= 0; j--) {
      if (dp[n][j]) {
        diff = sum - 2 * j;
        break;
      }
    }
    return diff;
  }
};

int main()
{
  vector<int> nums1({1, 6, 11, 5});

  Solution solution;
  cout << solution.findMin(nums1) << endl;
  return 0;
}