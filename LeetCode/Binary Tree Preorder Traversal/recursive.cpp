#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (NULL == root) return ans;
    preorderTraversal(root, ans);
    return ans;
  }
private:
  void preorderTraversal(TreeNode* root, vector<int>& ans) {
    if (NULL == root) return;
    ans.push_back(root->val);
    if (NULL != root->left) preorderTraversal(root->left, ans);
    if (NULL != root->right) preorderTraversal(root->right, ans);
    return;
  }
};

std::ostream& operator<<(std::ostream& stream, vector<int>& nums) {
  for (auto it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return stream;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  root->right = n1;
  n1->left = n2;

  Solution solution;
  vector<int> ans = solution.preorderTraversal(root);
  cout << ans << endl;
  return 0;
}
