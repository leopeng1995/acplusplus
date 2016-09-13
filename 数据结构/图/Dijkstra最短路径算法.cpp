// 单源最短路问题2（Dijkstra算法）
// 在图中存在负边的情况下，Dijkstra算法就无法正确求解问题，需要使用Bellman-Ford算法

int cost[MAX_V][MAX_V]; // cost[u][v]表示边e={u,v}的权值（不存在这条边时设为INF）
int d[MAX_V];           // 顶点s出发的最短距离
bool used[MAX_V];       // 已经使用过的图
int V;

// 求从起点s出发到各个顶点的最短距离
void dijkstra(int s) {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;

  while (true) {
    int v = -1;
    // 从尚未使用过的顶点中选择一个距离最小的顶点
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (v == -1|| d[u] < d[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < V; ++u) {
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
}

// 使用STL的priority_queue实现。在每次更新时往堆里插入当前最短距离和顶点的值对。
// 当取出的最小值不是最短距离的话，就丢弃这个值。
struct edge { int to, cost; };
typedef pair<int, int> P; // first是最短距离，second是顶点的编号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  // 通过制定greater<P>参数，堆按照first从小到大的顺序取出值
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    if (d[v] < p.first) continue;
    int v = p.second;
    for (unsigned int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

// 路径还原，增加prev[]数组
int prev[MAX_V];  // 最短路上的前驱顶点
void dijkstra(int s) {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  fill(prev, prev + V, -1);
  d[s] = 0;

  while (true) {
    int v = -1;
    // 从尚未使用过的顶点中选择一个距离最小的顶点
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (v == -1|| d[u] < d[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < V; ++u) {
      if (d[u] > d[v] + cost[v][u]) {
        d[u] = d[v] + cost[v][u];
        prev[u] = v;
      }
    }
  }
}

// 到顶点t的最短路
vector<int> get_path(int t) {
  vector<int> path;
  for (; t != -1; t = prev[t]) path.push_back(t); // 不断沿着prev[t]走直到t=s
  // 这样得到的是按照t到s顺序，所以要翻转
  reverse(path.begin(), path.end());
  return path;
}
