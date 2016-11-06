// DFS + 回溯
// 过不了POJ
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  Solution() {
    for (int i = 0; i < 9; i++) mask[i] = pow(2, 9) - 1 - pow(2, i);
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    dfs(board);
  }
private:
  bool dfs(vector<vector<char>>& board) {
    for (int i = 0; i < (int)board.size(); i++)
      for (int j = 0; j < (int)board.back().size(); j++) {
        if (board[i][j] == '.') {
          for (int k = 1; k <= 9; k++) {
            if (check(board, i, j, k)) {
              board[i][j] = k + '0';
              if (dfs(board)) return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    return true;
  }
  bool check(vector<vector<char>>& board, int x, int y, int k) {
    int permit = 511; // 111111111
    for (int j = 0; j < (int)board.back().size(); j++) if (board[x][j] != '.') permit &= mask[board[x][j] - '1'];
    for (int i = 0; i < (int)board.size(); i++) if (board[i][y] != '.') permit &= mask[board[i][y] - '1'];
    int block_x = x / 3, block_y = y / 3;
    block_x = block_x * 3;
    block_y = block_y * 3;
    for (int i = block_x; i < block_x + 3; i++)
      for (int j = block_y; j < block_y + 3; j++)
        if (board[i][j] != '.') permit &= mask[board[i][j] - '1'];
    if (permit == 0) return false;

    int bit_mask = 1;
    if ((bit_mask) << (k - 1) & permit) return true;
    return false;
  }
private:
  int mask[9];
};

int main()
{
  vector<vector<char>> board({
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  });

  Solution solution;
  solution.solveSudoku(board);

  for (auto i = board.begin(); i != board.end(); i++) {
    for (auto j = (*i).begin(); j < (*i).end(); j++)
      cout << *j;
    cout << endl;
  }
  return 0;
}
