#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A & V: Given n items with size A[i] and value V[i]
   * @return: The maximum value
   */
  int backPackII(int m, vector<int> A, vector<int> V) {
    if (m == 0) return 0;
    vector<int> dp;
    dp.resize(m + 1);

    int n = A.size();
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = m; j >= A[i]; j--)
        dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
    }
    return dp[m];
  }
};

int main()
{
  int m = 10;
  vector<int> A({2, 3, 5, 7});
  vector<int> V({1, 5, 2, 4});

  Solution solution;
  cout << solution.backPackII(m, A, V) << endl;
  return 0;
}