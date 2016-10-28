// O(n), Tricky
// http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (NULL == head) return NULL;
    int n = countList(head);
    return divide(&head, n);
  }
private:
  int countList(ListNode* head) {
    int n = 0;
    ListNode *p = head;
    while (p != NULL) {
      n++;
      p = p->next;
    }
    return n;
  }
private:
  TreeNode* divide(ListNode** head, int n) {
    if (n <= 0) return NULL;

    TreeNode* left = divide(head, n/2);
    TreeNode* root = new TreeNode((*head)->val);
    root->left = left;
    *head = (*head)->next;  // 重点

    root->right = divide(head, n-n/2-1);
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
  ListNode *l0 = new ListNode(1);
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(3);
  ListNode *l3 = new ListNode(4);
  ListNode *l4 = new ListNode(5);
  ListNode *l5 = new ListNode(6);
  ListNode *l6 = new ListNode(7);
  ListNode *l7 = new ListNode(8);
  ListNode *l8 = new ListNode(9);
  ListNode *l9 = new ListNode(10);
  l0->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = l6;
  l6->next = l7;
  l7->next = l8;
  l8->next = l9;

  Solution solution;
  TreeNode *root = solution.sortedListToBST(l0);
  cout << root << endl;
  return 0;
}
