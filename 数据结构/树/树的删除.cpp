// 树的删除，后序遍历
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root) {
  if (NULL == root) return;

  traverse(root->left);
  traverse(root->right);
  cout << root->val << endl;
  delete(root);
}

int main()
{
  TreeNode *d0 = new TreeNode(1);
  TreeNode *d1 = new TreeNode(2);
  TreeNode *d2 = new TreeNode(3);
  TreeNode *d3 = new TreeNode(4);
  TreeNode *d4 = new TreeNode(5);
  d0->left = d1;
  d0->right = d2;
  d1->left = d3;
  d1->right = d4;

  traverse(d0);
  return 0;
}
