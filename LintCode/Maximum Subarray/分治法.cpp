// 分治法，O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int max(int a, int b, int c) {
  return max(max(a, b), c);
}

class Solution {
public:
  int maxSubArray(vector<int> nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    return findMaximumSubArray(nums, 0, nums.size() - 1);
  }
private:
  int findMaximumSubArray(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];

    int mid = l + (r-l)/2;
    int left_sum = findMaximumSubArray(nums, l, mid);
    int right_sum = findMaximumSubArray(nums, mid + 1, r);
    int cross_sum = findMaxCrossingSubArray(nums, l, mid, r);
    return max(left_sum, right_sum, cross_sum);
  }
  int findMaxCrossingSubArray(vector<int>& nums, int l, int mid, int r) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= l; --i) {
      sum += nums[i];
      if (sum > left_sum)
        left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid + 1; j <= r; ++j) {
      sum += nums[j];
      if (sum > right_sum)
        right_sum = sum;
    }
    return (left_sum + right_sum);
  }
};


int main()
{
  vector<int> nums1({-2, 2, -3, 4, -1, 2, 1, -5, 3});

  Solution solution;
  cout << solution.maxSubArray(nums1) << endl;
  return 0;
}
