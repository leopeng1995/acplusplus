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

const int MAX_N = 1000 + 5;

int dp[MAX_N][MAX_N];
char lcs[MAX_N];

int main()
{
  freopen("in.txt", "r", stdin);
  char X[MAX_N];
  char Y[MAX_N];

  int T;
  sc(T);
  while (T--)
  {
    scanf("%s", X);
    scanf("%s", Y);
    int m = strlen(X), n = strlen(Y);
    for (int i = 0; i <= m; ++i)
    {
      for (int j = 0; j <= n; ++j)
      {
        if (i == 0 || j == 0) dp[i][j] = 0;
        else if (X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }

    int index = dp[m][n];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
      if (X[i-1] == Y[j-1])
      {
        lcs[index-1] = X[i-1];
        i--;
        j--;
        index--;
      }
      else if (dp[i-1][j] > dp[i][j-1]) i--;
      else j--;
    }

    printf("%d %s\n", dp[m][n], lcs);
    mset0(X);
    mset0(Y);
  }
  return 0;
}
