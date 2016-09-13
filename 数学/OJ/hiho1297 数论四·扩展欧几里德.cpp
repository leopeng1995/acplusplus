#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d\n", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// UVaOJ需要去掉改行

int64 gcd(int64 a, int64 b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int64 extgcd(int64 a, int64 b, int64& x, int64& y) {
  int64 d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

int64 solve(int64 s1, int64 s2, int64 v1, int64 v2, int64 m)
{
  int64 A = v1 - v2;
  int64 B = m;
  int64 C = s2 - s1;

  if (A < 0) A = A + m;
  int64 D = gcd(A, B);

  if (C % D) return -1;

  A = A / D;
  B = B / D;
  C = C / D;

  int64 x, y;
  extgcd(A, B, x, y);
  x = (x * C) % B;
  while (x < 0)
    x = x + B;

  return x;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int64 s1, s2, v1, v2, m;
  while (scanf("%lld%lld%lld%lld%lld", &s1, &s2, &v1, &v2, &m) != EOF)
    printf("%lld\n", solve(s1, s2, v1, v2, m));
  return 0;
}
