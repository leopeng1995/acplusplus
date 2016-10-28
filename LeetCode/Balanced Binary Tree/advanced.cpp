// 边递归，边统计高度，O(n)
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (NULL == root) return true;
    if (NULL == root->left && NULL == root->right) return true;

    int height = 0;
    return isBalanced(root, height);
  }
private:
  bool isBalanced(TreeNode* root, int& height) {
    if (NULL == root) {
      height = 0;
      return true;
    }

    int lh = 0, rh = 0;
    bool c1 = isBalanced(root->left, lh);
    bool c2 = isBalanced(root->right, rh);
    height = max(lh, rh) + 1;

    if (labs(lh - rh) >= 2) return false;
    return c1 && c2;
  }
};

int main()
{
  TreeNode* t1 = new TreeNode(1);
  TreeNode* t2 = new TreeNode(1);
  TreeNode* t3 = new TreeNode(1);
  TreeNode* t4 = new TreeNode(1);
  TreeNode* t5 = new TreeNode(1);
  TreeNode* t6 = new TreeNode(1);
  TreeNode* t7 = new TreeNode(1);
  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t3->right = t6;
  t5->left = t7;

  Solution solution;
  cout << solution.isBalanced(t1) << endl;
  return 0;
}
