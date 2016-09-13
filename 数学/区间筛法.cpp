// 区间内素数的个数
// 给定整数a和b，区间[a,b)内有多少个素数
// 思路：先分别做好[2,sqrt(b))的表和[a,b)的表，然后从[2,sqrt(b))的表中筛得素数的同时
//      ，也将其倍数从[a,b)的表中划去，最后剩下的就是区间[a,b)内的素数。

typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B]

void segment_sieve(ll a, ll b) {
  for (int i = 0; (ll)i * i < b; ++i) is_prime_small[i] = true;
  for (int i = 0; i < b - a; ++i) is_prime[i] = true;

  for (int i = 2; (ll)i * i < b; ++i) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false; // 筛[2,sqrt(b))
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) is_prime[j - a] = false;
      // 筛[a,b)
    }
  }
}
