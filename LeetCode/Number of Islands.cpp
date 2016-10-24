// 并查集 + BFS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int MAX_N = 100;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (0 == grid.size()) return 0;

    int num = 0;
    int grid_rows = grid.size();
    int grid_columns = grid.at(0).size();
    int grid_size = grid_rows * grid_columns;
    int grid_one_nums = 0;

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
              Point point;
              point.i = i;
              point.j = j;
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

        int i = point.i, j = point.j;
        // TODO: 下面应该换成方向数组
        if (i - 1 >= 0 && grid[i-1][j] == '1' && dis[(i-1)*grid_columns + j] == -1) {  // 上
          Point newPoint;
          newPoint.i = i - 1;
          newPoint.j = j;
          q.push(newPoint);
          dis[newPoint.i*grid_columns + newPoint.j] = 0;
          Unite(i*grid_columns + j, newPoint.i*grid_columns + newPoint.j);
        }
        if (i + 1 < grid_rows && grid[i+1][j] == '1' && dis[(i+1)*grid_columns + j] == -1) { // 下
          Point newPoint;
          newPoint.i = i + 1;
          newPoint.j = j;
          q.push(newPoint);
          dis[newPoint.i*grid_columns + newPoint.j] = 0;
          Unite(i*grid_columns + j, newPoint.i*grid_columns + newPoint.j);
        }
        if (j - 1 >= 0 && grid[i][j-1] == '1' && dis[i*grid_columns + j-1] == -1) {  // 左
          Point newPoint;
          newPoint.i = i;
          newPoint.j = j - 1;
          q.push(newPoint);
          dis[newPoint.i*grid_columns + newPoint.j] = 0;
          Unite(i*grid_columns + j, newPoint.i*grid_columns + newPoint.j);
        }
        if (j + 1 < grid_columns && grid[i][j+1] == '1' && dis[i*grid_columns + j+1] == -1) { // 右
          Point newPoint;
          newPoint.i = i;
          newPoint.j = j + 1;
          q.push(newPoint);
          dis[newPoint.i*grid_columns + newPoint.j] = 0;
          Unite(i*grid_columns + j, newPoint.i*grid_columns + newPoint.j);
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
  typedef struct Point {
    int i, j;
  } Point;
private:
  std::queue<Point> q;
private:
  int dis[100000];
  int parents[100000];
  int ranks[100000];

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
