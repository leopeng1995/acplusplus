// O(2^n)，重复计算子问题
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int MatrixChainOrder(vector<int>& nums, int i, int j) {
  if (i == j) return 0;

  int ans = INT_MAX;
  for (int k = i; k < j; k++) {
    ans = min(ans, MatrixChainOrder(nums, i, k) +
              MatrixChainOrder(nums, k + 1, j) +
              nums[i - 1] * nums[k] * nums[j]);
  }
  return ans;
}

int main()
{
  vector<int> nums({40, 20, 30, 10, 30});
  cout << MatrixChainOrder(nums, 1, nums.size() - 1) << endl;
  return 0;
}
