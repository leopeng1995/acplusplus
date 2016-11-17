// 只能通过83%的数据
// 重复的数据通不过
#include <iostream>
#include <string>
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

    string inT1("");
    string inT2("");
    inorder(T1, inT1);
    inorder(T2, inT2);
    inT1.push_back('#');
    inT2.push_back('#');
    if (inT1.find(inT2) == string::npos) return false;

    string preT1("");
    string preT2("");
    inorder(T1, preT1);
    inorder(T2, preT2);
    if (preT1.find(preT2) == string::npos) return false;
    preT1.push_back('#');
    preT2.push_back('#');
    return true;
  }
private:
  void inorder(TreeNode *root, string& s) {
    if (NULL == root) {
      s.push_back('$');
      return;
    }
    inorder(root->left, s);
    s.append(to_string(root->val));
    inorder(root->right, s);
    return;
  }
private:
  void preorder(TreeNode *root, string& s) {
    if (NULL == root) {
      s.push_back('$');
      return;
    }
    s.append(to_string(root->val));
    inorder(root->left, s);
    inorder(root->right, s);
    return;
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