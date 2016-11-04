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
typedef long long LL;
typedef long long int64;	// %lld

const int MAXN = 100 + 5;
int nums[MAXN];
int dp[MAXN][MAXN];
int n;

int MatrixChainOrder() {
  for (int i = 1; i < n; i++) dp[i][i] = 0;
  for (int L = 2; L < n; L++) {
    for (int i = 1; i < n - L + 1; i++) {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j]);
    }
  }
  return dp[1][n - 1];
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc(n) != EOF) {
    for (int i = 0; i < n; i++) sc(nums[i]);
    printf("%d\n", MatrixChainOrder());
  }
  return 0;
}
