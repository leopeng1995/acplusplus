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

const int SIGMA_SIZE = 26;
const int MAX_NODE = 500000 + 10;
const int MAX_SIZE = 1000000 + 10;

struct Trie {
  int next[MAX_NODE][SIGMA_SIZE], fail[MAX_NODE], cnt[MAX_NODE], val[MAX_NODE];
  int root;
  int sz;  // 结点总数
  Trie() { init(); }
  inline int idx(char c) { return c - 'a'; }

  int newnode() {
    memset(next[sz], -1, sizeof(next[sz]));
    cnt[sz++] = 0;
    return sz - 1;
  }
  void init() {
    sz = 0;
    root = newnode();
  }
  void insert(char buf[]) {
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (next[now][idx(buf[i])] == -1)
        next[now][idx(buf[i])] = newnode();
      now = next[now][idx(buf[i])];
    }
    cnt[now]++;
  }
  // 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”
  void insert(char buf[], int v) {
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (next[now][idx(buf[i])] == -1)
        next[now][idx(buf[i])] = newnode();
      now = next[now][idx(buf[i])];
    }
    cnt[now]++;
    val[now] = v;
  }
  void build() {
    queue<int> Q;
    fail[root] = root;
    for(int i = 0; i < SIGMA_SIZE; i++)
      if(next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while (!Q.empty()) {
      int now = Q.front();
      Q.pop();
      for (int i = 0; i < SIGMA_SIZE; i++)
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }
  int query(char buf[]) {
    int len = strlen(buf);
    int now = root;
    int res = 0;
    for (int i = 0; i < len; i++) {
      now = next[now][idx(buf[i])];
      int temp = now;
      while(temp != root) {
        res += cnt[temp];
        cnt[temp] = 0;
        temp = fail[temp];
      }
    }
    return res;
  }
};

char buf[MAX_SIZE];
Trie ac;
int T, n;

int main()
{
  freopen("in.txt", "r", stdin);
  sc(T);
  while (T--) {
    sc(n);
    ac.init();
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      ac.insert(buf);
    }
    ac.build();
    scanf("%s", buf);
    printf("%d\n", ac.query(buf));
  }
  return 0;
}