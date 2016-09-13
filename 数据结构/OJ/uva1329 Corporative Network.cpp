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

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d\n", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
//const double INF = 1e20;

const double PI = acos(-1.0);

typedef long long ll;
//typedef __int64 int64;

const int MAX_N = 20000 + 10;
int parents[MAX_N]; // 父亲
int ranks[MAX_N];   // 树的高度
int dist[MAX_N];    // dist[i] 结点i到树根的距离

void Init(int n) {
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    ranks[i] = 0;
    dist[i] = 0;
  }
}

int Find(int x) {
  if (parents[x] != x) {
    int root = Find(parents[x]);
    dist[x] += dist[parents[x]];
    return parents[x] = root;
  }
  else return x;
}

void Unite(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;

  if (ranks[x] < ranks[y]) {
    parents[x] = y;
  } else {
    parents[y] = x;
    if (ranks[x] == ranks[y]) ++ranks[x];
  }
}

bool Same(int x, int y) {
  return Find(x) == Find(y);
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  sc(T);
  while (T--)
  {
    int n, u, v;
    char cmd[9];
    sc(n);
    Init(n);
    while (scanf("%s", cmd) && cmd[0] != 'O')
    {
      if (cmd[0] == 'E') {
        sc(u);
        Find(u);
        printf("%d\n", dist[u]);
      }
      if (cmd[0] == 'I') {
        sc2(u, v);
        parents[u] = v;
        dist[u] = abs(u-v) % 1000;
      }
    }
  }
  return 0;
}
