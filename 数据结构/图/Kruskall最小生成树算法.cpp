// 最小生成树问题2（Kruskal算法）

int parents[MAX_N]; // 父亲
int ranks[MAX_N];   // 树的高度

void Init(int n) {
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int Find(int x) {
  if (parents[x] == x) {
    return x;
  } else {
    return parents[x] = Find(parents[x]);
  }
}

void Unite(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;

  if (ranks[x] < ranks[y]) {
    parents[x] = y;
  } else {
    parents[y] = x;
    if (ranks[x] == ranks[y]) ++ranks[x];
  }
}

bool Same(int x, int y) {
  return Find(x) == Find(y);
}

struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;   // 顶点数和边数

int kruskal() {
  sort(es, es + E, comp); // 按照edge.cost的顺序从小到大排列
  Init(V);                // 并查集的初始化
  int res = 0;
  for (int i = 0; i < E; ++i) {
    edge e = es[i];
    if (!Same(e.u, e.v)) {
      Unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}
