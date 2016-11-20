//#include <bits/stdc++.h>
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
#include <climits>
#include <cfloat>
using namespace std;

#define SCi(n) scanf("%d", &n)
#define SC2i(n) scanf("%d", &n)
#define SC3i(n) scanf("%d", &n)
#define SCf(n) scanf("%f", &n)
#define SC2f(n) scanf("%f", &n)
#define SC3f(n) scanf("%f", &n)
#define SCd(n) scanf("%lf", &n)
#define SC2d(n) scanf("%lf", &n)
#define SC3d(n) scanf("%lf", &n)

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix, n) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

int T, n;
int x, ans, MaxAi;
const int MAX_N = 100000 + 5;
int A[MAX_N];

int main()
{
  freopen("in.txt", "r", stdin);
  SCi(T);
  while (T--) {
    SCi(n);
    for (int i = 0; i < n; i++) {
      SCi(x);
      if (i == 0) { MaxAi = x; }
      else if (i == 1) { ans = MaxAi - x; MaxAi = max(MaxAi, x); }
      else { ans = max(ans, MaxAi - x); MaxAi = max(MaxAi, x); }
    }
    printf("%d\n", ans);
  }
  return 0;
}