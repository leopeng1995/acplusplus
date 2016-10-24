#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//const int MAXN = 10000;
//int dp[MAXN][MAXN];
//class NumArray {
//public:
//  NumArray(vector<int> &nums) {
//    memset(dp, 0, sizeof(dp));
//
//    int n = nums.size();
//    for (int i = 0; i < n; ++i)
//      dp[i][i] = nums[i];
//
//    for (int k = 1; k <= n - 1; ++k)
//      for (int i = 0, j = 0; i < n - k; ++i, ++j)
//        dp[i][k+j] = dp[i][k+j-1] + dp[i+1][k+j] - dp[i+1][k+j-1];
//  }
//
//  int sumRange(int i, int j) {
//    return dp[i][j];
//  }
//};

class NumArray {
public:
  NumArray(vector<int> &nums) {
    if (nums.empty()) return;

    sum.push_back(nums[0]);
    for (int i = 1; i < (int)nums.size(); ++i)
      sum.push_back(sum.back() + nums[i]);
  }

  int sumRange(int i, int j) {
    if (!i) return sum[j];
    return sum[j] - sum[i - 1];
  }
private:
  vector<int> sum;
};

int main()
{
  vector<int> nums({1, 3, 5, 7});
  NumArray numArray(nums);
  cout << numArray.sumRange(0, 1) << endl;
  cout << numArray.sumRange(1, 2) << endl;
  cout << numArray.sumRange(2, 3) << endl;
  cout << numArray.sumRange(3, 3) << endl;
  return 0;
}
