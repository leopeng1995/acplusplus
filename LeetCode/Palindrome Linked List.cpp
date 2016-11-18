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
  bool isPalindrome(ListNode* head) {
    if (NULL == head || NULL == head->next) return true;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;
    while (NULL != q->next) {
      p = p->next;
      q = q->next;
      if (NULL != q->next) q = q->next;
    }
    ListNode *head1 = head;
    ListNode *head2 = p->next;
    p->next = NULL;
    head2 = reverseList(head2);
    ListNode *p1 = head1, *p2 = head2;
    while (p1 && p2) {
      if (p1->val != p2->val) return false;
      p1 = p1->next;
      p2 = p2->next;
    }
    return true;
  }
private:
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
  ListNode *p1 = new ListNode(1);
  ListNode *p2 = new ListNode(2);
  p1->next = p2;
  p2->next = NULL;

  Solution solution;
  cout << solution.isPalindrome(p1) << endl;
//  while (p != NULL) {
//    cout << p->val << " ";
//    p = p->next;
//  }
//  cout << endl;
  return 0;
}