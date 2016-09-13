// hihoCoder 1015

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

const int PAT_MAX_SIZE = 10000 + 5;
const int TXT_MAX_SIZE = 1000000 + 5;

void computeLPSArray(char *pat, int N, int *lps) {
  lps[0] = 0;

  int i = 1, len = 0;
  while (i < N) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) len = lps[len-1];
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

int KMPSearch(char *txt, char *pat) {
  int M = strlen(txt);
  int N = strlen(pat);

  int *lps = (int *)malloc(sizeof(int)*N);
  computeLPSArray(pat, N, lps);

  int i = 0, j = 0;
  int ans = 0;
  while (i < M) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == N) {
      ans++;
      j = lps[j-1];
    }
    else if (i < M && pat[j] != txt[i]) {
      if (j != 0) j = lps[j-1];
      else i = i+1;
    }
  }
  free(lps); // to avoid memory leak
  return ans;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  sc(T);
  char pat[PAT_MAX_SIZE];
  char txt[TXT_MAX_SIZE];

  while (T--)
  {
    scanf("%s", pat);
    scanf("%s", txt);
    printf("%d\n", KMPSearch(txt, pat));
    mset0(pat);
    mset0(txt);
  }
  return 0;
}
