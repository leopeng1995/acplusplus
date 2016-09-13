// 任意两点间的最短路问题（Floyd-Warshall算法）
// 可以处理边是负数的情况。
// 判断图中是否存在负圈，检查是否存在d[i][i]是负数的顶点i

int d[MAX_V][MAX_V];
int V;

void warshall_floyd() {
  for (int k = 0; k < V ++k)
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
