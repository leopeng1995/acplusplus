// 参考LeetCode下的Edit Distance
// 关键是字符串比较从后往前想
// 可以先思考记忆化搜索（递归版）
// 再改成用数组递推计算
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

class Solution {
public:
  int minDistance(string& word1, string& word2) {
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    int m = word1.size(), n = word2.size();
    int dp[m+1][n+1];
    // 初始化
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) dp[i][0] = i;
    for (int i = 1; i <= n; i++) dp[0][i] = i;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
      }
    }
    return dp[m][n];
  }
};

int main()
{
  Solution solution;

  string str1("geek");
  string str2("gesek");
  cout << solution.minDistance(str1, str2) << endl;

  string str3("cat");
  string str4("cut");
  cout << solution.minDistance(str3, str4) << endl;

  string str5("sunday");
  string str6("saturday");
  cout << solution.minDistance(str5, str6) << endl;

  string str7("a");
  string str8("b");
  cout << solution.minDistance(str7, str8) << endl;
  return 0;
}
