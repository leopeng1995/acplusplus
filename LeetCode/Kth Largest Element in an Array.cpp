// 快速选择算法 QuickSelect
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) return -1;
    return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
  }
private:
  int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];

    int r = partition(nums, left, right);
    if (r == k) return nums[k];
    if (r > k) return quickselect(nums, left, r - 1, k);
    // r 在这里代表的是索引号，不是个数，所以不需要 k-r
    return quickselect(nums, r + 1, right, k);
  }
private:
  // partition 函数需要多加练习
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left;
    for (int j = left + 1; j <= right; ++j) {
      if (nums[j] <= pivot) {
        i = i + 1;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[left], nums[i]);
    return i;
  }
};

int main()
{
  vector<int> nums({3, 2, 1, 5, 6, 4});
  int k = 2;

  Solution solution;
  cout << solution.findKthLargest(nums, k) << endl;
  return 0;
}
