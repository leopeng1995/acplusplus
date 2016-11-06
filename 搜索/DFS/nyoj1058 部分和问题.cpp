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

const int MAX_N = 20 + 5;
int a[MAX_N];
int b[MAX_N];
int n, k, m;

bool dfs(int i, int sum) {
  if (i == n) return sum == k;
  if (sum > k) return false;
  if (sum == k) return true;

  if (dfs(i + 1, sum)) return true;
  if (dfs(i + 1, sum + a[i])) {
    b[m++] = a[i];
    return true;
  }
  return false;
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc2(n, k) != EOF) {
    for (int i = 0; i < n; i++) sc(a[i]);
    m = 0;
    bool flag = dfs(0, 0);
    printf("%s\n", (flag ? "YES" : "NO"));
    if (flag) for (int i = m - 1; i >= 0; i--) printf((i == 0 ? "%d\n" : "%d "), b[i]);
  }
  return 0;
}
