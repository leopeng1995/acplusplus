#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums.empty()) return 0;
    int sumTotal = 0;
    for (auto it = nums.begin(); it != nums.end(); it++)
      sumTotal += *it;
    return findMin(nums, nums.size() - 1, 0, sumTotal);
  }
private:
  int findMin(vector<int>& nums, int i, int sumCalculated, int sumTotal) {
    if (i == 0) return labs((sumTotal - sumCalculated) - sumCalculated);

    return min(findMin(nums, i - 1, sumCalculated + nums[i], sumTotal),
               findMin(nums, i - 1, sumCalculated, sumTotal));
  }
};

int main()
{
  vector<int> nums1({1, 6, 11, 5});

  Solution solution;
  cout << solution.findMin(nums1) << endl;
  return 0;
}