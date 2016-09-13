// 假设输入都是正数
// 素性测试O(sqrt(n))
bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return n != 1;  // 1是例外
}

// 约数枚举O(sqrt(n))
vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    res.push_back(i);
    if (i != n / i) res.push_back(n / i);
  }
  return res;
}

// 整数分解O(sqrt(n))
map<int, int> prime_factor(int n) {
  map<int, int> res;
  for (int i = 2; i * i <= n; ++i) {
    ++res[i];
    n /= i;
  }
  if (n != 1) res[n] = 1;
  return res;
}
