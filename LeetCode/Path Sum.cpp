#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (NULL == root) return false;
    return dfs(root, sum);
  }
private:
  bool dfs(TreeNode* root, int sum) {
    // 判断是否为叶子节点
    if (NULL == root->left && NULL == root->right && sum == root->val) return true;
    if (NULL == root->left && NULL == root->right && sum != root->val) return false;

    bool ans1 = false, ans2 = false;
    if (NULL != root->left)
      ans1 = dfs(root->left, sum - root->val);
    if (NULL != root->right)
      ans2 = dfs(root->right, sum - root->val);
    return ans1 || ans2;
  }
};

int main()
{
  TreeNode *root = new TreeNode(5);
  TreeNode *d1 = new TreeNode(4);
  TreeNode *d2 = new TreeNode(8);
  TreeNode *d3 = new TreeNode(11);
  TreeNode *d4 = new TreeNode(13);
  TreeNode *d5 = new TreeNode(4);
  TreeNode *d6 = new TreeNode(7);
  TreeNode *d7 = new TreeNode(2);
  TreeNode *d8 = new TreeNode(1);
  root->left = d1;
  root->right = d2;
  d1->left = d3;
  d2->left = d4;
  d2->right = d5;
  d3->left = d6;
  d3->right = d7;
  d5->right = d8;
//  TreeNode *root = new TreeNode(1);
//  TreeNode *d1 = new TreeNode(2);
//  root->left = d1;

  Solution solution;
  cout << solution.hasPathSum(root, 22) << endl;


  return 0;
}
