// dp[i][j] = A[i]*...*A[j]的最小值
// dp[i][j] = dp[i][k] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j]
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int MatrixChainOrder(vector<int>& nums, int n) {
  int dp[n][n];
  for (int i = 1; i < n; i++) dp[i][i] = 0;
  for (int L = 2; L < n; L++) {
    for (int i = 1; i < n - L + 1; i++) {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j]);
    }
  }
  return dp[1][n - 1];
}

int main()
{
  vector<int> nums({40, 20, 30, 10, 30});
  cout << MatrixChainOrder(nums, nums.size()) << endl;
  return 0;
}
