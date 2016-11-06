// 参考『矩阵最长递增序列』改进而来
#include <cstdio>
#include <cstring>
#include <cmath>
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
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// %lld

const int MAX_R = 100 + 5;
const int MAX_C = 100 + 5;
int mat[MAX_R][MAX_C];
int dp[MAX_R][MAX_C];
int R, C;

int findLongestFromACell(int i, int j) {
  if (i < 0 || i >= R || j < 0 || j >= C) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int val = -1;

  if (j < C - 1 && (mat[i][j] < mat[i][j + 1]) && (findLongestFromACell(i, j + 1) > val))
    val = findLongestFromACell(i, j + 1);

  if (j>0 && (mat[i][j] < mat[i][j - 1]) && (findLongestFromACell(i, j - 1) > val))
    val = findLongestFromACell(i, j - 1);

  if (i > 0 && (mat[i][j] < mat[i - 1][j]) && (findLongestFromACell(i - 1, j) > val))
    val = findLongestFromACell(i - 1, j);

  if (i < R - 1 && (mat[i][j] < mat[i + 1][j]) && (findLongestFromACell(i + 1, j) > val))
    val = findLongestFromACell(i + 1, j);

  if (val == -1) return dp[i][j] = 1;
  dp[i][j] = val + 1;
  return dp[i][j];
}

int findLongestOverAll() {
  int result = 1;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (dp[i][j] == -1) findLongestFromACell(i, j);
      result = max(result, dp[i][j]);
    }
  }
  //DEBUG_PRINT_MATRIX2(dp, R, C);

  return result;
}

int main()
{
  freopen("in.txt", "r", stdin);
  sc2(R, C);
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      sc(mat[i][j]);
  //DEBUG_PRINT_MATRIX2(mat, R, C);

  memset(dp, -1, sizeof(dp));

  printf("%d\n", findLongestOverAll());
  return 0;
}
