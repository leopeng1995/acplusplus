#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff

const double PI = acos(-1.0);

typedef long long ll;
typedef __int64 int64;

const int MAX_N = 10000 + 5;
int N, K;
double L[MAX_N];

// 判断是否满足条件
bool C(double x) {
  int num = 0;
  for (int i = 0; i < N; ++i) num += (int)(L[i] / x);
  return num >= K;
}

void solve() {
  // 初始化解的范围
  double lb = 0, ub = INF;

  // 重复循环，直到解的范围足够小
  for (int i = 0; i < 100; ++i) {
    double mid = (lb + ub) / 2;
    if (C(mid)) lb = mid;
    else ub = mid;
  }

  printf("%.2f\n", floor(ub * 100) / 100);
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (sc2(N, K) != EOF) {
    for (int i = 0; i < N; ++i) scanf("%lf", &L[i]);
    solve();
  }
  return 0;
}
