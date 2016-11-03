#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool findPartition(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return false;
    int sum = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) sum += *it;
    if (sum % 2 != 0) return false;
    return isSubsetSum(nums, nums.size(), sum / 2);
  }
private:
  bool isSubsetSum(vector<int>& nums, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;

    if (nums[n - 1] > sum) return isSubsetSum(nums, n - 1, sum);
    return isSubsetSum(nums, n - 1, sum)
        || isSubsetSum(nums, n - 1, sum - nums[n - 1]);
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
