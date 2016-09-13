#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define scarr(n,arr) for(int i = 0; i < n; ++i) sc(arr[i])
#define INF 0xffffff

typedef long long ll;
typedef __int64 int64;

const int N = 10;
int k, MOD;
int arr[N], f[N];

struct Matrix {
  int64 mat[N][N];
  Matrix operator*(const Matrix& m) const {
    Matrix ret;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ret.mat[i][j] = 0;
        for (int k = 0; k < N; ++k) {
          ret.mat[i][j] += mat[i][k] * m.mat[k][j] % MOD;
          ret.mat[i][j] %= MOD;
        }
      }
    }
    return ret;
  }
};

int64 Pow(Matrix &m, int k) {
  Matrix ans;
  memset(ans.mat, 0, sizeof(ans.mat));
  for (int i = 0; i < N; ++i) ans.mat[i][i] = 1;
  k -= 9;
  while (k) {
    if (k & 1) ans = ans * m;
    k >>= 1;
    m = m * m;
  }
  int64 sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += ans.mat[0][i] * f[N - i - 1] % MOD;
    sum %= MOD;
  }
  return sum;
}

void init(Matrix& m) {
  memset(m.mat, 0, sizeof(m.mat));
  for(int i = 0 ; i < N ; i++) m.mat[0][i] = arr[i];
  for(int i = 0 ; i < N-1 ; i++) m.mat[i + 1][i] = 1;
  for(int i = 0 ; i < N ; i++) f[i] = i;
}

int main()
{
    freopen("in.txt", "r", stdin);
    Matrix m;
    while (sc2(k, MOD) != EOF)
    {
      scarr(N, arr);
      init(m);
      if (k < 10) printf("%d\n", k % MOD);
      else printf("%I64d\n", Pow(m, k));
    }
    return 0;
}
