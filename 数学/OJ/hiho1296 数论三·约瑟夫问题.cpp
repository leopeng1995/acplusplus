#include <cstdio>
#include <cstring>

int Josephus(int N, int K)
{
  if (N == 1) return 0;
  int ret;
  if (N < K)
  {
    ret = 0;
    for (int i = 2; i <= N; ++i)
      ret = (ret + K) % i;
    return ret;
  }
  ret = Josephus(N - N / K, K);
  if (ret < N % K)
    ret = ret - N % K + N;
  else
    ret = ret - N % K + (ret - N % K) / (K - 1);
  return ret;
}

int main()
{
  freopen("in.txt", "r", stdin);

  int n, k;
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d", &n, &k);
    printf("%d\n", Josephus(n, k));
  }
  return 0;
}
