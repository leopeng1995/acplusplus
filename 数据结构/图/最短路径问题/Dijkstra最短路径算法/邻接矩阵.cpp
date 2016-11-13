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

const int MAX_V = 1000 + 5;
int dist[MAX_V][MAX_V]; // dist[u][v] 表示边 e = {u, v} 的长度（不存在这条边时设为INT_MAX）
int cost[MAX_V][MAX_V]; // cost[u][v] 表示边 e = {u, v} 的权值（不存在这条边时设为INT_MAX）
int d[MAX_V];           // 顶点s出发的最短距离
int c[MAX_V];           // 顶点s出发的花费
bool used[MAX_V];       // 已经使用过的图顶点
int V, E; // 顶点数、边数
int s, t; // 源点、终点
int p, v; // 距离、花费

// 求从起点s出发到各个顶点的最短距离
void dijkstra(int s) {
  fill(d, d + V, INT_MAX);
  fill(c, c + V, INT_MAX);
  fill(used, used + V, false);
  d[s] = 0;
  c[s] = 0;

  while (true) {
    int v = -1;
    // 从尚未使用过的顶点中选择一个距离最小的顶点
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < V; ++u) {
      if (dist[v][u] == INT_MAX) continue;
      d[u] = min(d[u], d[v] + dist[v][u]);
      c[u] = min(c[u], c[v] + cost[v][u]);
    }
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc2(V, E) != EOF) {
    if (!V && !E) break;
    for (int i = 0; i < MAX_V; i++)
      for (int j = 0; j < MAX_V; j++)
        dist[i][j] = INT_MAX, cost[i][j] = INT_MAX;

    for (int i = 0; i < E; i++) {
      sc2(s, t);
      sc2(p, v);
      dist[s - 1][t - 1] = dist[t - 1][s - 1] = p;
      cost[s - 1][t - 1] = cost[t - 1][s - 1] = v;
    }
    sc2(s, t);
    dijkstra(s - 1);
    printf("%d %d\n", d[t - 1], c[t - 1]);
  }
  return 0;
}