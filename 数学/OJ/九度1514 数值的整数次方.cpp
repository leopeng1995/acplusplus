// 该题的知识点为快速幂

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
typedef long long int64;	// %lld

int main()
{
  freopen("in.txt", "r", stdin);
  int n, exponent;
  double base;

  while (sc(n) != EOF)
  {
    for (int i = 0; i < n; ++i)
    {
      scanf("%lf%d", &base, &exponent);
      if (base != 0.0)
      {
        if (exponent < 0)
        {
          exponent = -exponent;
          base = 1.0 / base;
        }
        double ans = 1.0;

        while (exponent)
        {
          if (exponent & 1) ans *= base;
          base *= base;
          exponent >>= 1;
        }
        printf("%1.2ef\n", ans);
      }
      else
        printf("%s", (exponent > 0) ? "0.00e+00f\n" : "INF\n");
    }
  }
  return 0;
}
