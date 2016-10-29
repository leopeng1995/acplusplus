// 入度为零的顶点入队列
// O(V+E) ???
#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
  Graph(int V);
  void addEdge(int u, int v);
  void topologicalSort();
private:
  int V;
  list<int> *adj;
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
}

void Graph::topologicalSort() {
  vector<int> in_degree(V, 0);

  for (int u = 0; u < V; u++) {
    for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
      in_degree[*itr]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++)
    if (in_degree[i] == 0)
      q.push(i);

  int cnt = 0;
  vector <int> top_order;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    top_order.push_back(u);

    for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
      if (--in_degree[*itr] == 0)
        q.push(*itr);

    cnt++;
  }

  if (cnt != V) {
    cout << "There exists a cycle in the graph\n";
    return;
  }

  for (int i = 0; i < top_order.size(); i++)
    cout << top_order[i] << " ";
  cout << endl;
}

int main()
{
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.topologicalSort();
  return 0;
}
