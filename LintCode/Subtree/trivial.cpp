#include <iostream>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   * @param T1, T2: The roots of binary tree.
   * @return: True if T2 is a subtree of T1, or false.
   */
  bool isSubtree(TreeNode *T1, TreeNode *T2) {
    if (NULL == T1 && NULL == T2) return true;
    if (NULL == T2) return true;
    if (NULL == T1) return false;

    if (isIdentical(T1, T2)) return true;
    return (isSubtree(T1->left, T2) ||
            isSubtree(T1->right, T2));
  }
private:
  bool isIdentical(TreeNode *root1, TreeNode *root2) {
    if (NULL == root1 && NULL == root2) return true;
    if (NULL == root1 || NULL == root2) return false;

    return (root1->val == root2->val &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
  }
};

int main()
{
  TreeNode *root1 = new TreeNode(1);
  TreeNode *r11 = new TreeNode(2);
  TreeNode *r12 = new TreeNode(3);
  TreeNode *r13 = new TreeNode(4);
  root1->left = r11;
  root1->right = r12;
  r12->left = r13;

  TreeNode *root2 = new TreeNode(3);
  TreeNode *r21 = new TreeNode(4);
  root2->left = r21;

  Solution solution;
  cout << solution.isSubtree(root1, root2) << endl;
  return 0;
}