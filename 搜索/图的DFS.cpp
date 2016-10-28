// 邻接表存储，用STL的list实现
#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
  Graph(int V);
  void addEdge(int v, int w);
  void dfs(int v);
private:
  int V;
  list<int> *adj;
  void dfs(int v, bool visited[]);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::dfs(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";

  for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
    if (!visited[*it])
      dfs(*it, visited);
}

void Graph::dfs(int v) {
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  dfs(v, visited);
  cout << endl;
}

int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal (starting from vertex 2)" << endl;
  g.dfs(2);
  return 0;
}
