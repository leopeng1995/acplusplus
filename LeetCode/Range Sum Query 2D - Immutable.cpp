// 动态规划
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return;
    vector<int> v;
    v.push_back(matrix[0][0]);
    for (int i = 1; i < (int)matrix[0].size(); ++i)
      v.push_back(v.back() + matrix[0][i]);
    dp.push_back(v);

    for (int i = 1; i < (int)matrix.size(); ++i) {
      v.clear();
      v.push_back(dp[i-1][0] + matrix[i][0]);
      for (int j = 1; j < (int)matrix[i].size(); ++j)
        v.push_back(v.back() + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j]);
      dp.push_back(v);
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 == 0 && col1 == 0) return dp[row2][col2];
    if (row1 == 0) return dp[row2][col2] - dp[row2][col1-1];
    if (col1 == 0) return dp[row2][col2] - dp[row1-1][col2];
    return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
  }
private:
  vector<vector<int>> dp;
};

int main()
{
  vector<vector<int>> matrix({
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  });
  NumMatrix numMatrix(matrix);
  cout << numMatrix.sumRegion(0, 0, 1, 1) << endl; // 14
  cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; // 8
  cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; // 11
  cout << numMatrix.sumRegion(1, 2, 2, 4) << endl; // 12
  return 0;
}
