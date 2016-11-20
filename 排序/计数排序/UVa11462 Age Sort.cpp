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
typedef long long int64;  // %lld

const int MAX_N = 100;  // 年龄范围1~100
int n, x, c[MAX_N + 1];

int main()
{
  freopen("in.txt", "r", stdin);
  while (SCi(n) == 1 && n) {
    mset0(c);
    for (int i = 0; i < n; i++) {
      SCi(x);
      c[x]++;
    }
    bool first = true;
    for (int i = 1; i <= MAX_N; i++) {
      for (int j = 0; j < c[i]; j++) {
        if (!first) printf(" ");
        first = false;
        printf("%d", i);
      }
    }
    printf("\n");
  }
  return 0;
}