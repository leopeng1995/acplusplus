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

const int MAX_N = 100000 + 10;
int parents[MAX_N]; // ¸¸Ç×
int ranks[MAX_N];   // Ê÷µÄ¸ß¶È

void Init(int n) {
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int Find(int x) {
  return parents[x] != x ? parents[x] = Find(parents[x]) : x;
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
  //freopen("in.txt", "r", stdin);
  int x, y;
  while (sc(x) == 1)
  {
    Init(MAX_N);
    int refusals = 0;
    while (x != -1)
    {
      sc(y);
      x = Find(x);
      y = Find(y);
      if (x == y) ++refusals;
      else Unite(x, y);
      sc(x);
    }
    printf("%d\n", refusals);
  }
  return 0;
}
