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
int Layer[SIZE];
bool Visited[SIZE];
int n, m; // m是顶点数目，顶点编号从1开始 1是源，m是汇，n是边数

bool CountLayer() {
  deque<int> q;
  memset(Layer,0xff,sizeof(Layer));//都初始化成-1
  Layer[1] = 0;
  q.push_back(1);

  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for(int j = 1; j <= m; ++j) {
      if(G[v][j] > 0 && Layer[j] == -1) {
        //Layer[j] == -1 说明j还没有访问过
        Layer[j] = Layer[v] + 1;
        if(j == m) return true; //分层到汇点即可
        else q.push_back(j);
      }
    }
  }
  return false;
}

int Dinic() {
  int i;
  int nMaxFlow = 0;
  deque<int> q;//DFS用的栈
  while( CountLayer() ) { //只要能分层
    q.push_back(1); //源点入栈
    memset(Visited,0,sizeof(Visited));
    Visited[1] = 1;

    while(!q.empty()) {
      int nd = q.back();
      if(nd == m) { // nd是汇点
        //在栈中找容量最小边
        int nMinC = INF;
        int nMinC_vs; //容量最小边的起点
        for(i = 1; (unsigned)i < q.size(); ++i) {
          int vs = q[i - 1];
          int ve = q[i];
          if(G[vs][ve] > 0) {
            if(nMinC > G[vs][ve]) {
              nMinC = G[vs][ve];
              nMinC_vs = vs;
            }
          }
        }
        //增广，改图
        nMaxFlow += nMinC;
        for(i = 1; (unsigned)i < q.size(); ++i) {
          int vs = q[i - 1];
          int ve = q[i];
          G[vs][ve] -= nMinC; //修改边容量
          G[ve][vs] += nMinC; //添加反向边
        }
        //退栈到 nMinC_vs成为栈顶，以便继续dfs
        while(!q.empty() && q.back() != nMinC_vs) {
          Visited[q.back()] = 0; //没有这个应该也对
          q.pop_back();
        }
      }
      else { //nd不是汇点
        for(i = 1; i <= m; ++i) {
          if(G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 && !Visited[i]) { //只往下一层的没有走过的节点走
            Visited[i] = 1;
            q.push_back(i);
            break;
          }
        }
        if(i > m) q.pop_back(); //找不到下一个点，则回溯
      }
    }
  }
  return nMaxFlow;
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
      printf("%d\n", Dinic());
    }
    return 0;
}
