#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    if (nums1.empty() || nums2.empty()) return ans;
    unordered_set<int> s1, s2;
    for (auto it = nums1.begin(); it != nums1.end(); it++) s1.insert(*it);
    for (auto it = nums2.begin(); it != nums2.end(); it++) s2.insert(*it);
    for (auto it = s1.begin(); it != s1.end(); it++)
      if (s2.find(*it) != s2.end())
        ans.push_back(*it);
    return ans;
  }
};

int main()
{
  vector<int> nums1({1, 2, 2, 1});
  vector<int> nums2({2, 2});

  Solution solution;
  vector<int> ans = solution.intersection(nums1, nums2);
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
