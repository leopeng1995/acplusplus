### 背包问题 Backpack

判定性背包问题，[LintCode Backpack](http://www.lintcode.com/en/problem/backpack/)

使用滚动数组：

```
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
```

0-1背包（最基础的模型），[LintCode Backpack II](http://www.lintcode.com/en/problem/backpack-ii/)

使用滚动数组：

```
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
```