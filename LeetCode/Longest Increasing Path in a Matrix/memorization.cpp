// 与POJ1088滑雪相同的解法
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int rows = matrix.size(), cols = matrix.back().size();
    vector<vector<int>> dp;
    dp.resize(rows);
    for (int i = 0; i < rows; i++) dp[i].resize(cols, -1);

    int result = 1;
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        if (dp[i][j] == -1) longestIncreasingPath(matrix, dp, i, j);
        result = max(result, dp[i][j]);
      }
    return result;
  }
private:
  int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
    int R = matrix.size(), C = matrix.back().size();
    if (i < 0 || i >= R || j < 0 || j >= C) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int val = -1;
    if (j < C - 1 && (matrix[i][j] < matrix[i][j + 1]) && (longestIncreasingPath(matrix, dp, i, j + 1) > val))
      val = longestIncreasingPath(matrix, dp, i, j+1);
    if (j>0 && (matrix[i][j] < matrix[i][j - 1]) && (longestIncreasingPath(matrix, dp, i, j - 1) > val))
      val = longestIncreasingPath(matrix, dp, i, j - 1);
    if (i > 0 && (matrix[i][j] < matrix[i - 1][j]) && (longestIncreasingPath(matrix, dp, i - 1, j) > val))
      val = longestIncreasingPath(matrix, dp, i - 1, j);
    if (i < R - 1 && (matrix[i][j] < matrix[i + 1][j]) && (longestIncreasingPath(matrix, dp, i + 1, j) > val))
      val = longestIncreasingPath(matrix, dp, i + 1, j);

    if (val == -1) return dp[i][j] = 1;
    dp[i][j] = val + 1;
    return dp[i][j];
  }
};

int main()
{
  vector<vector<int>> matrix1({
    {9, 9, 4},
    {6, 6, 8},
    {2, 1, 1}
  });
  vector<vector<int>> matrix2({
    {3, 4, 5},
    {3, 2, 6},
    {2, 2, 1}
  });
  vector<vector<int>> matrix3({
    {7, 7, 5},
    {2, 4, 6},
    {8, 2, 0}
  });

  Solution solution;
  cout << solution.longestIncreasingPath(matrix1) << endl;
  cout << solution.longestIncreasingPath(matrix2) << endl;
  cout << solution.longestIncreasingPath(matrix3) << endl;
  return 0;
}
