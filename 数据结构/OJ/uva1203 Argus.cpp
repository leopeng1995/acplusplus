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

struct Item
{
  int QNum, Period, Time;
  bool operator < (const Item& a) const {
    return Time > a.Time || (Time == a.Time && QNum > a.QNum);
  }
};

int main()
{
  freopen("in.txt", "r", stdin);
  priority_queue<Item> pq;
  char s[20];

  while (scanf("%s", s) && s[0] != '#')
  {
    Item item;
    sc2(item.QNum, item.Period);
    item.Time = item.Period;
    pq.push(item);
  }

  int K;
  sc(K);
  while (K--)
  {
    Item r = pq.top();
    pq.pop();
    printf("%d\n", r.QNum);
    r.Time += r.Period;
    pq.push(r);
  }
  return 0;
}
