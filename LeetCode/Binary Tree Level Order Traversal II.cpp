// queue + stack
// 能否改进？
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
    stack<stack<int>> s;
    while (!q.empty()) {
      int n = q.size();
      stack<int> s1, s2;
      while (n--) {
        TreeNode *p = q.front();
        q.pop();
        s2.push(p->val);
        if (NULL != p->left) q.push(p->left);
        if (NULL != p->right) q.push(p->right);
      }
      while (!s2.empty()) {
        int val = s2.top();
        s2.pop();
        s1.push(val);
      }
      s.push(s1);
    }

    while (!s.empty()) {
      stack<int> ss = s.top();
      s.pop();
      vector<int> v;
      while (!ss.empty()) {
        int val = ss.top();
        ss.pop();
        v.push_back(val);
      }
      ans.push_back(v);
    }
    return ans;
  }
};

std::ostream& operator<<(std::ostream& stream, vector<vector<int>> ans) {
  for (auto i = ans.begin(); i != ans.end(); ++i) {
    for (auto j = (*i).begin(); j != (*i).end(); ++j) {
      cout << *j << " ";
    }
    cout << endl;
  }
  return stream;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  TreeNode *t1 = new TreeNode(9);
  TreeNode *t2 = new TreeNode(20);
  TreeNode *t3 = new TreeNode(15);
  TreeNode *t4 = new TreeNode(7);
  root->left = t1;
  root->right = t2;
  t2->left = t3;
  t2->right = t4;

  Solution solution;
  cout << solution.levelOrderBottom(root) << endl;
  return 0;
}
