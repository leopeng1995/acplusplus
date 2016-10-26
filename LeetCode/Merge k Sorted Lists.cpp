// 分治法，再利用 Merge Two Sorted Lists 的方法解决
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return mergeKLists(lists, 0, lists.size() - 1);
  }
private:
  ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
    if (l == r) return lists[l];

    int mid = l + (r-l)/2;
    ListNode *left = mergeKLists(lists, l, mid);
    ListNode *right = mergeKLists(lists, mid+1, r);
    return mergeTwoLists(left, right);
  }
private:
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

  ListNode *head3 = new ListNode(2);
  ListNode *p31 = new ListNode(4);
  ListNode *p32 = new ListNode(7);
  ListNode *p33 = new ListNode(11);
  ListNode *tail3 = new ListNode(14);
  head3->next = p31;
  p31->next = p32;
  p32->next = p33;
  p33->next = tail3;
  tail3->next = NULL;

  vector<ListNode*> lists;
  lists.push_back(head1);
  lists.push_back(head2);
  lists.push_back(head3);
  Solution solution;
  ListNode *p = solution.mergeKLists(lists);
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}
