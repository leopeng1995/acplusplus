// Simple Minimize Algorithm, 完全二叉树
// Input: 一组正整数，完全二叉树的叶子节点，2的整数幂
// Output: 最优解（对于Maximizer）
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// -1 代表该节点 val 值无效
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode() : val(-1), left(nullptr), right(nullptr) {}
};

class PerfectBinaryTree {
public:
  int minimize(vector<int>& nums) {
    int val = -1;
    TreeNode *root = minimize(nums, true, val, 0, nums.size()-1);
    return root->val;
  }
private:
  // 建树的同时进行Minimize
  TreeNode* minimize(vector<int>& nums, bool isMax, int& val, int l, int r) {
    if (l == r) {
      TreeNode *p = new TreeNode(nums[l]);
      val = nums[l];
      return p;
    }
    TreeNode* root = new TreeNode();
    int mid = l + (r-l)/2;
    int left_val = -1, right_val = -1;
    root->left = minimize(nums, !isMax, left_val, l, mid);
    root->right = minimize(nums, !isMax, right_val, mid+1, r);
    val = isMax ? max(left_val, right_val) : min(left_val, right_val);
    root->val = val;
    return root;
  }
};

int main()
{
  vector<int> nums({3, 5, 2, 9, 12, 5, 23, 23});

  PerfectBinaryTree tree;
  cout << tree.minimize(nums) << endl;
  return 0;
}
