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
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// %lld

const int MAX_N = 100000 + 5;
bool visited[MAX_N];

struct Step {
  int x;
  int steps;
  Step(int xx, int s) : x(xx), steps(s) {}
};
queue<Step> q;

int main()
{
  freopen("in.txt", "r", stdin);
  int N, K;
  while (sc2(N, K) != EOF)
  {
    mset0(visited);
    q.push(Step(N, 0));

    while (!q.empty())
    {
      Step s = q.front();
      q.pop();

      if (s.x == K)
      {
        printf("%d\n", s.steps);
        return 0;
      }

      if (s.x - 1 >= 0 && !visited[s.x - 1])
      {
        q.push(Step(s.x - 1, s.steps + 1));
        visited[s.x - 1] = 1;
      }
      if (s.x + 1 <= MAX_N && !visited[s.x + 1])
      {
        q.push(Step(s.x + 1, s.steps + 1));
        visited[s.x + 1] = 1;
      }
      if (s.x * 2 <= MAX_N && !visited[s.x * 2])
      {
        q.push(Step(s.x * 2, s.steps + 1));
        visited[s.x * 2] = 1;
      }
    }
  }
  return 0;
}
