#include <iostream>
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
  int maxDepth(TreeNode* root) {
    return dfs(root);
  }
private:
  int dfs(TreeNode* root) {
    if (root == NULL) return 0;

    int ans = max(dfs(root->left), dfs(root->right)) + 1;
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  TreeNode *d1 = new TreeNode(2);
  TreeNode *d2 = new TreeNode(3);
  TreeNode *d3 = new TreeNode(4);
  TreeNode *d4 = new TreeNode(5);
  TreeNode *d5 = new TreeNode(6);
  /* Above max depth is 3 */
  root->left = d1;
  root->right = d2;
  d1->left = d3;
  d2->left = d4;
  d4->right = d5;

  Solution solution;
  cout << solution.maxDepth(root) << endl;
  return 0;
}
