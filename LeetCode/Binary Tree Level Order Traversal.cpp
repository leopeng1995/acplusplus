// 树的层次遍历
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (NULL == root) return ans;
    if (NULL == root->left && NULL == root->right) {
      vector<int> v;
      v.push_back(root->val);
      ans.push_back(v);
      return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> v;
      while (n--) {
        TreeNode *p = q.front();
        q.pop();
        v.push_back(p->val);
        if (p->left != NULL) q.push(p->left);
        if (p->right != NULL) q.push(p->right);
      }
      ans.push_back(v);
    }
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(3);
  TreeNode *l = new TreeNode(9);
  TreeNode *r = new TreeNode(20);
  TreeNode *rl = new TreeNode(15);
  TreeNode *rr = new TreeNode(7);
  root->left = l;
  root->right = r;
  r->left = rl;
  r->right = rr;

  Solution solution;
  vector<vector<int>> ans = solution.levelOrder(root);
  for (auto i = ans.begin(); i != ans.end(); i++) {
    for (auto j = (*i).begin(); j != (*i).end(); j++)
      cout << *j << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
