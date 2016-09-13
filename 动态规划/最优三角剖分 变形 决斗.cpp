// NYISTOJ 110
// 编号为x的人能从所有人中胜出，必要条件是他能与自己“相遇”，即把环看成链，x点拆成两个在这条链的两端，中间的人全部被淘汰出局，x保持不败。

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
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d\n", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

#define L(x) (1 << (x))

#define INF 0xffffff
const double eps = 1e-6;
//const double INF = 1e20;

const double PI = acos(-1.0);

typedef long long ll;
//typedef __int64 int64;

const int MAX_N = 500 + 5;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n;

void solve() {
  memset(dp, 0, sizeof(dp));  // 不必要
  for (int i = 0; i < n; ++i) dp[i][(i + 1) % n] = 1;

//  DEBUG_PRINT_MATRIX(dp)
//  printf("\n");

  for(int i = 2; i <= n; ++i)
    for(int s = 0; s != n; ++s) {
      int e = (i + s) % n;
      for(int k = (s + 1) % n; k != e; ++k, k %= n)
        dp[s][e] = dp[s][e] || (dp[s][k] && dp[k][e] && (a[s][k] || a[e][k]));
    }

//  DEBUG_PRINT_MATRIX(dp)

  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (dp[i][i]) ++cnt;
  printf("%d\n", cnt);
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  sc(T);
  while (T--)
  {
    sc(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        sc(a[i][j]);

    solve();

    //DEBUG_PRINT_MATRIX(a)
  }
  return 0;
}
