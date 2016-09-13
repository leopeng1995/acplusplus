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
const int SIZE = 300;
int G[SIZE][SIZE];
int Prev[SIZE]; // 路径上每个节点的前驱节点
bool Visited[SIZE];
int n, m; // m是顶点数目，顶点编号从1开始 1是源，m是汇，n是边数

unsigned Augment() {
  int v;
  deque<int> q;
  memset(Prev, 0, sizeof(Prev));
  memset(Visited, 0, sizeof(Visited));

  Prev[1] = 0;
  Visited[1] = 1;
  q.push_back(1);
  bool bFindPath = false;
  // 用bfs寻找一条源到汇的可行路径
  while (!q.empty()) {
    v = q.front();
    q.pop_front();
    for (int i = 1; i <= m; ++i) {
      if (G[v][i] > 0 && Visited[i] == 0) { // 必须是依然有容量的边，才可以走
        Prev[i] = v;
        Visited[i] = 1;
        if (i == m) {
          bFindPath = true;
          q.clear();
          break;
        }
        else q.push_back(i);
      }
    }
  }
  if (!bFindPath) return 0;
  int nMinFlow = INF;
  v = m;
  // 寻找源到汇路径上容量最小的边，其容量就是此次增加的总流量
  while (Prev[v]) {
    nMinFlow = min(nMinFlow, G[Prev[v]][v]);
    v = Prev[v];
  }
  // 沿此路径添加反向边，同时修改路径上每条边的容量
  v = m;
  while (Prev[v]) {
    G[Prev[v]][v] -= nMinFlow;
    G[v][Prev[v]] += nMinFlow;
    v = Prev[v];
  }
  return nMinFlow;
}

int main()
{
    freopen("in.txt", "r", stdin);
    while (sc2(n, m) != EOF) {
      // m是顶点数目
      int s, e, c;
      memset(G, 0, sizeof(G));
      for (int i = 0; i < n; ++i) {
        sc3(s,e,c);
        G[s][e] += c; // 两点之间可能有多条边
      }
      unsigned int MaxFlow = 0;
      unsigned int aug;
      while ((aug = Augment())) MaxFlow += aug;
      printf("%d\n", MaxFlow);
    }
    return 0;
}
