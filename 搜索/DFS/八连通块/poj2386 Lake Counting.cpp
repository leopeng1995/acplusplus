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
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("% ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

const int MAX_N = 100 + 5;
const int MAX_M = 100 + 5;
char field[MAX_N][MAX_M];
int N, M;

void dfs(int x, int y) {
  field[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
    }
  }
  return;
}

void solve() {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      if (field[i][j] == 'W') {
        dfs(i, j);
        ans++;
      }
  }
  printf("%d\n", ans);
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc2(N, M) != EOF) {
    for (int i = 0; i < N; i++) {
      getchar();
      for (int j = 0; j < M; j++)
        scanf("%c", &field[i][j]);
    }
    solve();
  }
  return 0;
}
