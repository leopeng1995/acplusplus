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

const int MAXN = 100000 + 5;
int dp_max[MAXN][20];
int dp_min[MAXN][20];
int mm[MAXN];
int A[MAXN];

void initRMQ(int n,int b[]) {
  mm[0] = -1;
  for(int i = 1; i <= n;i++) {
    mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
    dp_max[i][0] = b[i];
    dp_min[i][0] = b[i];
  }
  for(int j = 1; j <= mm[n];j++)
    for(int i = 1;i + (1<<j) -1 <= n;i++)
    {
      dp_max[i][j] = max(dp_max[i][j-1],dp_max[i+(1<<(j-1))][j-1]);
      dp_min[i][j] = min(dp_min[i][j-1],dp_min[i+(1<<(j-1))][j-1]);
    }
}

int rmq_max(int L, int R) {
  int k = mm[R-L+1];
  return max(dp_max[L][k], dp_max[R-(1<<k)+1][k]);
}

int rmq_min(int L, int R) {
  int k = mm[R-L+1];
  return min(dp_min[L][k], dp_min[R-(1<<k)+1][k]);
}

int main()
{
  freopen("in.txt", "r", stdin);
  int N, Q, m, n;
  sc2(N, Q);
  for (int i = 1; i <= N; ++i) sc(A[i]);
  initRMQ(N, A);
  for (int i = 0; i < Q; ++i)
  {
    sc2(m, n);
    printf("%d\n", rmq_max(m, n) - rmq_min(m, n));
  }
  return 0;
}
