// 记忆化搜索，会超时
#include <iostream>
#include <string>
using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

class Solution {
public:
  int minDistance(string& word1, string& word2) {
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();
    return minDistance(word1, word2, word1.size(), word2.size());
  }
private:
  int minDistance(string& word1, string& word2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (word1[m - 1] == word2[n - 1])
      return minDistance(word1, word2, m - 1, n - 1);

    return 1 + min(minDistance(word1, word2, m, n - 1),
                   minDistance(word1, word2, m - 1, n),
                   minDistance(word1, word2, m - 1, n - 1));
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
  return 0;
}
