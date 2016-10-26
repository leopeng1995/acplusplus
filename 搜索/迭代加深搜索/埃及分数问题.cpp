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
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

const int MAXN = 10000;
int ans[MAXN];
int v[MAXN];
int maxd, a, b, ansd;

LL gcd(LL a, LL b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int get_first(LL a, LL b) {
  int c = 1;
  while (b > a * c) c++;
  return c;
}

bool better(int d) {
  for (int i = d; i>= 0; --i)
    if (v[i] != ans[i]) {
      return ans[i] == -1 || v[i] < ans[i];
    }
  return false;
}

// 当前深度为d，分母不能小于from，分数之和恰好为aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
  if (d == maxd) {
    if (bb % aa) return false;
    if (aa == 0) return false;
    v[d] = bb/aa;
    if (better(d)) {
      memcpy(ans, v, sizeof(LL) * (d+1));
      ansd = d;
    }
    return true;
  }
  bool ok = false;
  from = max(from, get_first(aa, bb));
  for (int i = from; ; ++i) {
    // 剪枝：如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过aa/bb，则无解
    if (bb * (maxd+1-d) <= i * aa) break;
    v[d] = i;
    // 计算aa/bb - 1/i，设结果为a2/b2
    LL b2 = bb*i;
    LL a2 = aa*i - bb;
    LL g = gcd(a2, b2); // 以便约分
    if (g == 0) return false;
    if (dfs(d+1, i+1, a2/g, b2/g)) ok = true;
  }
  return ok;
}

int main()
{
  freopen("in.txt", "r", stdin);
  while (scanf("%d/%d", &a, &b) != EOF) {
    if (!a || !b) continue;
    int ok = 0;
    for (maxd = 1; ; ++maxd) {
      memset(ans, -1, sizeof(ans));
      //printf("%d\n", get_first(a, b));
      if (dfs(0, get_first(a, b), a, b)) {
        ok = 1;
        break;
      }
    }
    if (ok) {
//      printf("%d/%d=", a, b);
//      for (int i = 0; ans[i] != 0; ++i)
//        printf((i == 0 ? "1/%d" : "+1/%d"), ans[i]);
//      printf("\n");
      for (int i = 0; i < ansd; i++)
        printf("1/%d + ", ans[i]);
      printf("1/%d\n", ans[ansd]);
    }
  }
  return 0;
}
