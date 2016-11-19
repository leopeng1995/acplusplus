#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A: Given n items with size A[i]
   * @return: The maximum size
   */
  int backPack(int m, vector<int>& A) {
    if (m == 0) return 0;
    vector<bool> dp;
    dp.resize(m + 1);
    fill(dp.begin(), dp.end(), false);

    dp[0] = true;
    int n = A.size();
    for (int i = 0; i < n; i++) {
      for (int j = m; j >= A[i]; j--)
        dp[j] = dp[j] | dp[j - A[i]];
    }
    int ans = m;
    while (ans > 0) {
      if (dp[ans]) break;
      ans--;
    }
    return ans;
  }
};

int main()
{
  vector<int> A({2, 3, 5, 7});

  Solution solution;
  cout << solution.backPack(11, A) << endl;
  cout << solution.backPack(12, A) << endl;
  return 0;
}