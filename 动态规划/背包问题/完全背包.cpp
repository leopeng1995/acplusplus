const int MAX_N = 100000;
int dp[MAX_N + 10];
int c[MAX_N + 10], w[MAX_N + 10];
int n, V;

void solve() {
  mset0(dp);
  for (int i = 0; i < n; ++i)
    for (int j = V; j >= c[i]; --j)
      dp[j] = max(dp[j], dp[j - c[i]] + w[i]);

  printf("%d\n", dp[V]);
}