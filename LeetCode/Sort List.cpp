// 链表归并排序
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;

    ListNode *tail = head;
    while (tail->next != NULL)
      tail = tail->next;
    return sortList(head, tail);
  }
private:
  ListNode* sortList(ListNode* l1, ListNode* l2) {
    if (l1 == l2) return l1;

    ListNode *p1, *p2;
    p1 = p2 = l1;
    while (p2 != l2) {
      p2 = p2->next;
      if (l2 == p2) break;
      else {
        p1 = p1->next;
        p2 = p2->next;
      }
    }
    ListNode *mid = p1->next;
    p1->next = NULL;

    ListNode *n1 = sortList(l1, p1);
    ListNode *n2 = sortList(mid, l2);
    ListNode *p = sortTwoList(n1, n2);
    return p;
  }
private:
  ListNode* sortTwoList(ListNode* l1, ListNode* l2) {
    if (l1 == l2) return l1;

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
  ListNode *l0 = new ListNode(9);
  ListNode *l1 = new ListNode(4);
  ListNode *l2 = new ListNode(6);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(0);
  ListNode *l5 = new ListNode(2);
  ListNode *l6 = new ListNode(8);
  ListNode *l7 = new ListNode(1);
  ListNode *l8 = new ListNode(5);
  ListNode *l9 = new ListNode(7);
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
  ListNode *p = solution.sortList(l0);
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}
