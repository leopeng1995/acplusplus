#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.resize(m + n);
    int i = m - 1, j = n - 1;
    int p = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[p--] = nums1[i--];
      } else {
        nums1[p--] = nums2[j--];
      }
    }
    while (j >= 0) nums1[p--] = nums2[j--];
  }
};

int main()
{
//  vector<int> nums1({1, 4, 10, 15});
//  vector<int> nums2({2, 3, 11, 20});
  vector<int> nums1({4, 5, 6, 0, 0, 0});
  vector<int> nums2({1, 2, 3});
  Solution solution;
  solution.merge(nums1, 3, nums2, 3);
  for (auto it = nums1.begin(); it != nums1.end(); ++it)
    cout << *it << " ";
  cout << endl;
  return 0;
}
