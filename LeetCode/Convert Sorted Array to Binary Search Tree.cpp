#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return NULL;
    return divide(nums, 0, nums.size() - 1);
  }
private:
  TreeNode* divide(vector<int>& nums, int l, int r) {
    if (l > r) return NULL; // 这里是重点！为什么不能 l == r ?
    int mid = l + ceil((r-l)/2.0);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = divide(nums, l, mid-1);
    root->right = divide(nums, mid+1, r);
    return root;
  }
};

std::ostream& operator<<(std::ostream &stream, TreeNode *root) {
  if (NULL == root) return stream;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *p = q.front();
    q.pop();
    if (p->left != NULL) q.push(p->left);
    if (p->right != NULL) q.push(p->right);
    stream << p->val << " ";
  }
  stream << endl;
  return stream;
}

int main()
{
  vector<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  Solution solution;
  TreeNode *root = solution.sortedArrayToBST(nums);
  cout << root << endl;
  return 0;
}
