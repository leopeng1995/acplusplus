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
using namespace std;

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

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;  // %lld

const int MAX_NODE = 400000 + 10;
const int MAX_SIGMA = 26;

struct Trie {
  int ch[MAX_NODE][MAX_SIGMA];
  int val[MAX_NODE];
  int sz;
  Trie() { init(); }
  void init() { sz = 1; mset0(ch[0]); }
  inline int idx(char c) { return c - 'a'; }
  
  int newnode() {
    mset0(ch[sz]);
    val[sz++] = 0;
    return sz - 1;
  }
  // 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
  void insert(const char *s, int v) {
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++){
      int c = idx(s[i]);
      if(!ch[u][c]) ch[u][c] = newnode();
      u = ch[u][c];
    }
    val[u] = v;
  }
  void query(const char *s, vector<int>& ans) {
    int u = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
      if (s[i] == '\0') break;
      int c = idx(s[i]);
      if (!ch[u][c]) break;
      u = ch[u][c];
      if (val[u]) ans.push_back(val[u]);
    }
  }
};

const int MOD = 20071027;
const int MAX_TEXT_LENGTH = 300000 + 10;
const int MAX_WORD_LENGTH = 100 + 10;
const int MAX_SIZE = 4000 + 10;

int dp[MAX_TEXT_LENGTH], len[MAX_SIZE];
char text[MAX_TEXT_LENGTH], word[MAX_WORD_LENGTH];
Trie trie;

int main()
{
  freopen("in.txt", "r", stdin);
  int S, cas = 0;
  while (scanf("%s%d", text, &S) == 2){
    trie.init();
    for (int i = 1; i <= S; i++){
      scanf("%s", word);
      len[i] = strlen(word);
      trie.insert(word, i);
    }
    mset0(dp);
    int n = strlen(text);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--){
      vector<int> p;
      trie.query(text + i, p);
      for (int j = 0; j < (int)p.size(); j++)
        dp[i] = (dp[i] + dp[i + len[p[j]]]) % MOD;
    }
    printf("Case %d: %d\n", ++cas, dp[0]);
  }
  return 0;
}