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

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;  // %lld

const int MAX_N = 1000;
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

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  sc(T);
  while (T--)
  {
    sc2(n, V);
    for (int i = 0; i < n; ++i) sc(w[i]);
    for (int i = 0; i < n; ++i) sc(c[i]);
    solve();
  }
  return 0;
}
