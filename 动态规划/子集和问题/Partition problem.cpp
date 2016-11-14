#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_N = 100 + 5;
const int MAX_SUM = 100000 + 5;
int dp[MAX_SUM][MAX_N];

class Solution {
public:
  bool findPartition(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) return false;
    int sum = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) sum += *it;
    if (sum % 2 != 0) return false;
    int n = nums.size();

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= sum/2; i++) dp[i][0] = 0;
    for (int i = 1; i <= sum/2; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = dp[i][j-1];
        if (i >= nums[j-1])
          dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
      }
    }
    return dp[sum/2][n];
  }
};

int main()
{
  freopen("in.txt", "r", stdin);
  Solution solution;
//  vector<int> nums1({1, 5, 11, 5});
//  vector<int> nums2({1, 5, 3});
//
//  cout << solution.findPartition(nums1) << endl;
//  cout << solution.findPartition(nums2) << endl;

  vector<int> nums;
  int T, n, num;
  
  scanf("%d", &T);
  while (T--) {
    nums.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &num);
      nums.push_back(num);
    }
    if (solution.findPartition(nums)) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}