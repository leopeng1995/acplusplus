#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  /**
   * @param triangle: a list of lists of integers.
   * @return: An integer, minimum path sum.
   */
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) return 0;
    int n = triangle.size();
    int dp[n + 1][n + 1];
    for (int j = 1; j <= n; j++) dp[n][j] = triangle[n - 1][j - 1];
    for (int i = n - 1; i >= 1; i--)
      for (int j = 1; j <= i; j++)
        dp[i][j] = triangle[i - 1][j - 1] + min(dp[i + 1][j], dp[i + 1][j + 1]);

    return dp[1][1];
  }
};

int main()
{
  vector<vector<int>> triangle({
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3}
  });

  Solution solution;
  cout << solution.minimumTotal(triangle) << endl;
  return 0;
}