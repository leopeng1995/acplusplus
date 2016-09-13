// 算法思想：倒置相加再还原
// 算法复杂度：O(n)

// string版
const int MAX_L = 110;
string add(string &a, string &b) {
  string ans;
  int na[MAX_L] = {0}, nb[MAX_L] = {0};
  int la = a.size(), lb = b.size();
  for (int i = 0; i < la; ++i) na[la - 1 - i] = a[i] - '0';
  for (int i = 0; i < lb; ++i) nb[lb - 1 - i] = b[i] - '0';
  int lmax = max(la, lb);
  for (int i = 0; i < lmax; ++i) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
  if (na[lmax]) ++lmax;
  for (int i = lmax - 1; i >= 0; --i) ans += na[i] + '0';
  return ans;
}

// 字符数组char[]版
// TODO
