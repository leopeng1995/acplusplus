#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty()) return ans;
    vector<int> B;
    int n = nums.size();
    B.resize(n);
    print_subset(ans, nums, B, 0);
    return ans;
  }
private:
  void print_subset(vector<vector<int>>& ans, vector<int>& nums, vector<int>& B, int cur) {
    int n = nums.size();
    if (cur == n) {
      vector<int> v;
      for (int i = 0; i < cur; i++)
        if (B[i]) v.push_back(nums[i]);
      ans.push_back(v);
      return;
    }
    B[cur] = 1; // 选第cur个元素
    print_subset(ans, nums, B, cur + 1);
    B[cur] = 0; // 不选第cur个元素
    print_subset(ans, nums, B, cur + 1);
  }
};

std::ostream& operator<<(std::ostream& stream, vector<vector<int>>& ans) {
  for (auto i = ans.begin(); i != ans.end(); i++) {
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }
  return stream;
}

int main()
{
  vector<int> nums1({1, 2, 4});
  Solution solution;
  vector<vector<int>> ans1 = solution.subsets(nums1);
  cout << ans1 << endl;
  return 0;
}
