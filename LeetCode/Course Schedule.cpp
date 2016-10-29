// Kahn's algorithm
// TODO: DFS+辅助栈
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
  Graph(int V);
  void addEdge(int u, int v);
  bool topologicalSort();
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

bool Graph::topologicalSort() {
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

  if (cnt != V) return false;
  return true;
}

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (numCourses == 0) return true;
    Graph g(numCourses);
    for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it)
      g.addEdge((*it).second, (*it).first);
    return g.topologicalSort();
  }
};

int main()
{
  int numCourses = 2;
  pair<int, int> p1({1, 0});
  pair<int, int> p2({0, 1});
  vector<pair<int, int>> v;
  v.push_back(p1);
  v.push_back(p2);
  Solution solution;
  cout << solution.canFinish(numCourses, v) << endl;
  return 0;
}
