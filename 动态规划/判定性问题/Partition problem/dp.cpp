// dp[i][j] = true if a subset of {arr[0], arr[1], ..arr[j-1]} has sum 
// equal to i, otherwise false
// dp[i][j] = dp[i][j-1] || dp[i-nums[j-1]][j-1]
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
  bool findPartition(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return false;
    int sum = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) sum += *it;
    if (sum % 2 != 0) return false;
    int n = nums.size();
    int dp[sum/2+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= sum/2; i++) dp[i][0] = 0;
    for (int i = 1; i <= sum/2; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i][j-1];
        if (i >= nums[j-1])
          dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
      }
    }
    return dp[sum/2][n];
  }
};

int main()
{
  vector<int> nums1({1, 5, 11, 5});
  vector<int> nums2({1, 5, 3});

  Solution solution;
  cout << solution.findPartition(nums1) << endl;
  cout << solution.findPartition(nums2) << endl;
  return 0;
}
