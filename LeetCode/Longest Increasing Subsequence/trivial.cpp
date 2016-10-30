// 最长上升子序列
// O(n^2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    int dp[n];
    fill(dp, dp + n, 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);

    int ans = -1;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    return ans;
  }
};

int main()
{
  vector<int> nums({10, 9, 2, 5, 3, 7, 101, 18});

  Solution solution;
  cout << solution.lengthOfLIS(nums) << endl;
  return 0;
}
