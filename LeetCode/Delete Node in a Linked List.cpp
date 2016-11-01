// 该题考察对指针作为函数参数的理解
// 指针本质上是指向一个空间（对象）的地址
// (*node)实际访问的就是那个对象
// (*node).next也就是下一个结点，用它的地址直接替换掉上一个节点的地址。
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    *node = *((*node).next);
  }
};

int main()
{
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;

  Solution solution;
  solution.deleteNode(l3);

  while (l1 != NULL) {
    cout << l1->val << " ";
    l1 = l1->next;
  }
  cout << endl;
  return 0;
}
