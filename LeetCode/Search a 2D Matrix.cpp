#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int rows = matrix.size();
    int columns = matrix.back().size();

    int u = 0, d = rows - 1;
    int mid1;
    while (u <= d) {
      mid1 = u + (d-u)/2;
      if (target > matrix[mid1][columns-1]) u = mid1 + 1;
      else if (target < matrix[mid1][columns-1]) {
        if (target < matrix[mid1][0]) d = mid1 - 1;
        else if (target > matrix[mid1][0]) break;
        else return true;
      }
      else return true;
    }

    int l = 0, r = columns - 1;
    while (l <= r) {
      int mid2 = l + (r-l)/2;
      if (target > matrix[mid1][mid2]) l = mid2 + 1;
      else if (target < matrix[mid1][mid2]) r = mid2 - 1;
      else if (target == matrix[mid1][mid2]) return true;
    }
    return false;
  }
};

int main()
{
  vector<vector<int>> matrix({
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  });

  Solution solution;
  cout << solution.searchMatrix(matrix, 1) << endl;
  cout << solution.searchMatrix(matrix, 3) << endl;
  cout << solution.searchMatrix(matrix, 5) << endl;
  cout << solution.searchMatrix(matrix, 7) << endl;
  cout << solution.searchMatrix(matrix, 10) << endl;
  cout << solution.searchMatrix(matrix, 11) << endl;
  cout << solution.searchMatrix(matrix, 16) << endl;
  cout << solution.searchMatrix(matrix, 20) << endl;
  cout << solution.searchMatrix(matrix, 23) << endl;
  cout << solution.searchMatrix(matrix, 30) << endl;
  cout << solution.searchMatrix(matrix, 34) << endl;
  cout << solution.searchMatrix(matrix, 50) << endl;
  cout << solution.searchMatrix(matrix, 51) << endl;
  cout << solution.searchMatrix(matrix, -1) << endl;
  cout << solution.searchMatrix(matrix, 4) << endl;
  cout << solution.searchMatrix(matrix, 80) << endl;
  cout << solution.searchMatrix(matrix, 9) << endl;
  cout << solution.searchMatrix(matrix, 13) << endl;
  return 0;
}
