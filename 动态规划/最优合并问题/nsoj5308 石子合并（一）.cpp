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
#define DEBUG_PRINT_MATRIX(matrix, n) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

const int MAX_N = 200 + 5;
int dp_max[MAX_N][MAX_N];
int dp_min[MAX_N][MAX_N];
int nums[MAX_N];
int sum[MAX_N];
int n;

void solve() {
  for (int i = 0; i < n; i++) {
    dp_min[i][i] = 0;
    dp_max[i][i] = 0;
  }
  for (int L = 1; L < n; L++) {
    for (int i = 0; i < n - L; i++) {
      int j = i + L;
      dp_min[i][j] = INT_MAX;
      dp_max[i][j] = INT_MIN;
      int s = sum[j] - (i > 0 ? sum[i - 1] : 0);
      for (int k = i; k < j; k++) {
        dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + s);
        dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + s);
      }
    }
  }
//  DEBUG_PRINT_MATRIX(dp_min, n);
//  DEBUG_PRINT_MATRIX(dp_max, n);
  printf("%d\n", dp_min[0][n - 1]);
  //printf("%d\n", dp_max[0][n - 1]);
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc(n) != EOF) {
    for (int i = 0; i < n; i++) sc(nums[i]);
    sum[0] = nums[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
    solve();
  }
  return 0;
}
