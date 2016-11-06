// O(N*M)
// 如果队列搜索到空，则会生成到每一个点的最近距离
// 可以全部初始化为INF
// 空间效率可以改进
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
typedef long long int64;  // %lld

const int MAX_N = 5;
int maze[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int xx, int yy) : x(xx), y(yy) {}
};
Point directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Node {
  int x, y;
  int dis;
  Node *prev;
  Point path[MAX_N * MAX_N];  // 可以改为指向父节点的指针
  Node(int xx, int yy, int d) : x(xx), y(yy), dis(d), prev(NULL) {}
};

void bfs() {
  queue<Node> q;
  Node root(0, 0, 0);
  q.push(root);

  while (!q.empty()) {
    Node p = q.front();
    q.pop();
    visited[p.x][p.y] = 1;

    if (p.x == MAX_N - 1 && p.y == MAX_N - 1) {
      //printf("%d\n", p.dis);
      for (int i = 0; i < p.dis; i++)
        printf("(%d, %d)\n", p.path[i].x, p.path[i].y);
      printf("(4, 4)\n");
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = p.x + directions[i].x;
      int ny = p.y + directions[i].y;
      if (0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_N && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
        Node r(nx, ny, p.dis + 1);
        for (int j = 0; j < p.dis; j++) r.path[j] = p.path[j];
        Point prev(p.x, p.y);
        r.path[r.dis - 1] = prev;
        r.prev = &p;
        q.push(r);
      }
    }
  }
}

int main()
{
  freopen("in.txt", "r", stdin);
  for (int i = 0; i < MAX_N; i++)
    for (int j = 0; j < MAX_N; j++)
      sc(maze[i][j]);
  //DEBUG_PRINT_MATRIX(maze, MAX_N);
  mset0(visited);
  bfs();
  return 0;
}
