#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (NULL == head || NULL == head->next) return NULL;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = head;
    ListNode *q = head;
    ListNode *r = &dummy;

    while (n--) q = q->next;
    while (q != NULL) {
      q = q->next;
      p = p->next;
      r = r->next;
    }
    r->next = p->next;
    delete(p);
    return dummy.next;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  ListNode *p1 = new ListNode(2);
  ListNode *p2 = new ListNode(3);
  ListNode *p3 = new ListNode(4);
  ListNode *tail = new ListNode(5);
  head->next = p1;
  p1->next = p2;
  p2->next = p3;
  p3->next = tail;
  tail->next = NULL;

  Solution solution;
  ListNode *p = solution.removeNthFromEnd(head, 2);
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
  return 0;
}
