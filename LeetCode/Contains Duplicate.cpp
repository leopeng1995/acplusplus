#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return false;
    unordered_set<int> s;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (s.find(*it) == s.end()) s.insert(*it);
      else return true;
    }
    return false;
  }
};

int main()
{
  vector<int> nums1({1, 2, 3});
  vector<int> nums2({1, 2, 2});
  vector<int> nums3({});

  Solution solution;
  cout << solution.containsDuplicate(nums1) << endl;
  cout << solution.containsDuplicate(nums2) << endl;
  cout << solution.containsDuplicate(nums3) << endl;
  return 0;
}
