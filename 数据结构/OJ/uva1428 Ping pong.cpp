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
//const double INF = 1e20;

const double PI = acos(-1.0);

typedef long long ll;
//typedef __int64 int64;

const int MAX_N = 20000 + 5;
const int MAX_S = 100000 + 5;
int a[MAX_N];
long long c[MAX_N], d[MAX_N];
int BIT[MAX_S];
int n, T;

void init(int n) {
  for (int i = 0; i < n; ++i) BIT[i] = 0;
}

int query(int x) {
  int ret = 0;
  for (; x; ret += BIT[x], x -= lowbit(x));
  return ret;
}

void modify(int x, int d) {
  for (; x <= n; BIT[x] += d, x += lowbit(x));
}

void solve() {
  sc(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    sc(a[i]);
    m = max(m, a[i]);
  }

  init(m);
  for (int i = 0; i < n; ++i) {
    c[i] = query(a[i]);
    modify(a[i], 1);
  }
  init(m);
  for (int i = n - 1; i >= 0; --i) {
    d[i] = query(a[i]);
    modify(a[i], 1);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i)
    ans += c[i] * (n - i - d[i]) + (i - c[i] - 1) * d[i];

  printf("%lld\n", ans);
}

int main()
{
  freopen("in.txt", "r", stdin);
  sc(T);
  while (T--)
  {
    solve();
  }
  return 0;
}
