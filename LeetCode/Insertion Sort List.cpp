#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = head->next;
    head->next = NULL;

    while (p != NULL) {
      ListNode *q = &dummy;
      ListNode *r = dummy.next;

      while (r != NULL) {
        if (r->val <= p->val) {
          r = r->next;
          q = q->next;
        }
        else break;
      }
      ListNode *s = p;
      p = p->next;
      s->next = r;
      q->next = s;
    }
    return dummy.next;
  }
};

int main()
{
  ListNode *l0 = new ListNode(7);
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(6);
  ListNode *l3 = new ListNode(1);
  ListNode *l4 = new ListNode(3);
  ListNode *l5 = new ListNode(4);
  ListNode *l6 = new ListNode(9);
  ListNode *l7 = new ListNode(5);
  ListNode *l8 = new ListNode(0);
  ListNode *l9 = new ListNode(8);
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
  ListNode *p = solution.insertionSortList(l0);
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}
