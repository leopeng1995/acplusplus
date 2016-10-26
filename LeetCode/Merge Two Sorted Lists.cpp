// 增加一个哨兵结点（哑结点dummy）
#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (NULL == l2) return l1;
    if (NULL == l1) return l2;
    ListNode dummy(-1);
    ListNode *p = &dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }
    p->next = l1 != NULL ? l1 : l2;
    return dummy.next;
  }
};

int main()
{
  ListNode *head1 = new ListNode(1);
  ListNode *p11 = new ListNode(3);
  ListNode *p12 = new ListNode(6);
  ListNode *p13 = new ListNode(10);
  ListNode *tail1 = new ListNode(20);
  head1->next = p11;
  p11->next = p12;
  p12->next = p13;
  p13->next = tail1;
  tail1->next = NULL;

  ListNode *head2 = new ListNode(2);
  ListNode *p21 = new ListNode(5);
  ListNode *p22 = new ListNode(9);
  ListNode *p23 = new ListNode(11);
  ListNode *tail2 = new ListNode(15);
  head2->next = p21;
  p21->next = p22;
  p22->next = p23;
  p23->next = tail2;
  tail2->next = NULL;

  Solution solution;
  ListNode *p = solution.mergeTwoLists(head1, head2);
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}
