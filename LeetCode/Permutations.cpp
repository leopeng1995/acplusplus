#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> A;
    permute_helper(ans, nums, A, 0);
    return ans;
  }
private:
  void permute_helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &A, unsigned int cur) {
    if (cur == nums.size()) {
      vector<int> B(A);
      ans.push_back(B);
      return;
    }
    for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
      bool ok = true;
      for (vector<int>::const_iterator it2 = A.begin(); it2 != A.end(); ++it2) {
        if (*it == *it2) {
          ok = false;
        }
      }
      if (ok) {
        A.push_back(*it);
        permute_helper(ans, nums, A, cur + 1);
        A.pop_back(); // 清理现场
      }
    }
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = solution.permute(nums);
  for (vector<vector<int>>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
    for (vector<int>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
      cout << *it2 << (it2 == (*it).end() - 1 ? "\n" : " ");
    }
  }
  return 0;
}
