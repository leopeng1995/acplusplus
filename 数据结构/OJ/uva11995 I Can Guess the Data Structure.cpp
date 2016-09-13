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

int main()
{
  freopen("in.txt", "r", stdin);
  queue<int> q;
  priority_queue<int> pq;
  stack<int> s;

  int n, a, b;
  while (sc(n) != EOF)
  {
    int ans = 0;  // a3.a2.a1 queue priority_queue stack
    int flag_q = 0, flag_pq = 0, flag_s = 0;
    while (q.size()) q.pop();
    while (pq.size()) pq.pop();
    while (s.size()) s.pop();
    for (int i = 0; i < n; ++i)
    {
      sc2(a, b);
      if (a == 1)
      {
        q.push(b);
        pq.push(b);
        s.push(b);
      }
      else
      {
        if (!q.empty() && !flag_q)
        {
          if (q.front() == b) ans |= 4;
          else
          {
            ans &= 3;
            flag_q = 1;
          }
          q.pop();
        }
        else
        {
          ans &= 3;
          flag_q = 1;
        }
        if (!pq.empty() && !flag_pq)
        {
          if (pq.top() == b) ans |= 2;
          else
          {
            ans &= 5;
            flag_pq = 1;
          }
          pq.pop();
        }
        else
        {
          ans &= 5;
          flag_pq = 1;
        }
        if (!s.empty() && !flag_s)
        {
          if (s.top() == b) ans |= 1;
          else
          {
            ans &= 6;
            flag_s = 1;
          }
          s.pop();
        }
        else
        {
          ans &= 6;
          flag_s = 1;
        }
      }
    }
    if (ans == 1) printf("stack\n");
    else if (ans == 2) printf("priority queue\n");
    else if (ans == 4) printf("queue\n");
    else if (ans == 0) printf("impossible\n");
    else printf("not sure\n");
  }

  return 0;
}
