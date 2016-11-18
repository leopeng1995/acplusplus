#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;
    reverseList(&head);
    return head;
  }
private:
  void reverseList(ListNode** head_ref) {
    ListNode* prev = NULL;
    ListNode* current = *head_ref;
    while (current != NULL) {
      ListNode* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    *head_ref = prev;
  }
};

int main()
{
  ListNode *head = new ListNode(3);
  ListNode *p1 = new ListNode(4);
  ListNode *p2 = new ListNode(7);
  ListNode *tail = new ListNode(1);
  head->next = p1;
  p1->next = p2;
  p2->next = tail;
  tail->next = NULL;

  Solution solution;
  ListNode *p = solution.reverseList(head);
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}