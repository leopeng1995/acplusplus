#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

typedef struct Point {
  int i, j;
} Point;

const int MAXN = 100000;
int dis[MAXN];
int parents[MAXN];
int ranks[MAXN];

void Init(int n) {
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int Find(int x) {
  return parents[x] != x ? parents[x] = Find(parents[x]) : x;
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

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (0 == grid.size()) return 0;

    int num = 0;
    int grid_rows = grid.size();
    int grid_columns = grid.at(0).size();
    int grid_size = grid_rows * grid_columns;
    int grid_one_nums = 0;

    Point directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    Init(grid_size);
    memset(dis, -1, sizeof(dis));

    for (int i = 0; i < grid_rows; ++i)
      for (int j = 0; j < grid_columns; ++j)
        if (grid[i][j] == '0')
          dis[i*grid_columns + j] = 0;
        else
          grid_one_nums++;

    while (num < grid_one_nums) {
      bool flag = false;
      for (int i = 0; i < grid_rows; ++i) {
        for (int j = 0; j < grid_columns; ++j) {
          if (dis[i*grid_columns + j] == -1) {
            if (grid[i][j] == '1') {
              flag = true;
              Point point = { .i = i, .j = j };
              q.push(point);
              break;
            }
          }
        }
        if (flag) break;
      }

      while (!q.empty()) {
        Point point = q.front();
        q.pop();
        dis[point.i*grid_columns + point.j] = 0;
        num++;

        for (int k = 0; k < 4; ++k) {
          int x = point.i + directions[k].i;
          int y = point.j + directions[k].j;
          if (x >= 0 && x < grid_rows && y >= 0 && y < grid_columns
              && grid[x][y] == '1' && dis[x*grid_columns + y] == -1) {
            Point newPoint = { .i = x, .j = y };
            q.push(newPoint);
            dis[x*grid_columns + y] = 0;
            Unite(point.i*grid_columns + point.j, newPoint.i*grid_columns + newPoint.j);
          }
        }
      }
    }

    set<int> s;
    for (int i = 0; i < grid_rows; ++i)
      for (int j = 0; j < grid_columns; ++j)
        if (grid[i][j] == '1')
          s.insert(Find(i*grid_columns + j));

    return s.size();
  }
private:
  std::queue<Point> q;
};

int main()
{
  Solution solution;
  vector<vector<char>> grid1 = {
    {'1', '1', '1', '1', '0'},
    {'1', '1', '0', '1', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0'}
  };
  cout << solution.numIslands(grid1) << endl;

  vector<vector<char>> grid2 = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
  };
  cout << solution.numIslands(grid2) << endl;
  return 0;
}