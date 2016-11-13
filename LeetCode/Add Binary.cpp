// 高精度加法
// 算法思想：倒置相加再还原
// 算法复杂度：O(n)
#include <iostream>
#include <string>
using namespace std;

const int MAX_L = 1000 + 10;
class Solution {
public:
  string addBinary(string& a, string& b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    return add(a, b, 2);
  }
private:
  string add(string& a, string& b, int base) {
    string ans;
    int na[MAX_L] = {0}, nb[MAX_L] = {0};
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la; ++i) na[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb; ++i) nb[lb - 1 - i] = b[i] - '0';
    int lmax = max(la, lb);
    for (int i = 0; i < lmax; ++i) na[i] += nb[i], na[i + 1] += na[i] / base, na[i] %= base;
    if (na[lmax]) ++lmax;
    for (int i = lmax - 1; i >= 0; --i) ans += na[i] + '0';
    return ans;
  }
};

int main()
{
  string a1("11");
  string b1("1");
  string a2("1010");
  string b2("101");

  Solution solution;
  cout << solution.addBinary(a1, b1) << endl;
  cout << solution.addBinary(a2, b2) << endl;
  return 0;
}
