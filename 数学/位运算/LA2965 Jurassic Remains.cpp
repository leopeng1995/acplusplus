// map: 0.029s
// unordered_map: 0.019s
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
#include <unordered_map>
using namespace std;

#define SCi(n) scanf("%d", &n)
#define SC2i(n,m) scanf("%d%d", &n, &m)
#define SC3i(n,m,t) scanf("%d%d%d", &n, &m, &t)
#define SCf(n) scanf("%f", &n)
#define SC2f(n,m) scanf("%f%f", &n, &m)
#define SC3f(n,m,t) scanf("%f%f%f", &n, &m, &t)
#define SCd(n) scanf("%lf", &n)
#define SC2d(n,m) scanf("%lf%lf", &n, &m)
#define SC3d(n,m,t) scanf("%lf%lf%lf", &n, &m, &t)
#define SCs(s) scanf("%s", s)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

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

inline int bitcount(int x) { return x == 0 ? 0 : bitcount(x / 2) + (x & 1); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

const int MAX_N = 24;
const int MAX_LENGTH = 1000;
int n;
int A[MAX_N];
//map<int, int> table;
unordered_map<int, int> table;
char s[MAX_LENGTH];

int main()
{
  freopen("in.txt", "r", stdin);
  while (SCi(n) != EOF && n) {
    for (int i = 0; i < n; i++) {
      SCs(s);
      A[i] = 0;
      for (int j = 0; s[j] != '\0'; j++) A[i] ^= (1 << (s[j] - 'A'));
    }
    table.clear();
    int n1 = n / 2, n2 = n - n1;
    for (int i = 0; i < (1 << n1); i++) {
      int x = 0;
      for (int j = 0; j < n1; j++) if (i & (1 << j)) x ^= A[j];
      if (!table.count(x) || bitcount(table[x]) < bitcount(i)) table[x] = i;
    }
    int ans = 0;
    for (int i = 0; i < (1 << n2); i++) {
      int x = 0;
      for (int j = 0; j < n2; j++) if (i & (1 << j)) x ^= A[n1 + j];
      if (table.count(x) && bitcount(ans) < bitcount(table[x]) + bitcount(i)) ans = (i << n1) ^ table[x];
    }
    printf("%d\n", bitcount(ans));
    for (int i = 0; i < n; i++) if (ans & (1 << i)) printf("%d ", i + 1);
    printf("\n");
  }
  return 0;
}