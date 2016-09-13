int prime[MAX_N];         // 第i个素数
bool is_prime[MAX_N + 1]; // is_prime[i]为true表示i是素数

// 返回n以内素数的个数 O(nloglogn)
int sieve(int n) {
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}
