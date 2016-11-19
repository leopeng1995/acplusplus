### 链表反转 Reverse Linked List

#### 迭代版 Iterative Method

```
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
```

Time Complexity: O(n)

Space Complexity: O(1)

#### 递归版 Recursive Method

1. Divide the list in two parts - first node and rest of the linked list.
2. Call reverse for the rest of the linked list.
3. Link rest to first.
4. Fix head pointer.

<div align="center">
  <img src="./Recursive Reverse Linked List.gif" width="420" height="400" alt="Recursive Reverse Linked List" align="center">
</div>
<br/>

```
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;
    reverseList(&head);
    return head;
  }
private:
  void reverseList(ListNode** head_ref) {
    if (NULL == *head_ref) return;

    ListNode* first = *head_ref;
    ListNode* rest = first->next;

    if (NULL == rest) return;
    reverseList(&rest);
    first->next->next = first;

    first->next = NULL;
    *head_ref = rest;
  }
};
```

Time Complexity: O(n)

Space Complexity: O(1)

#### 尾递归版 Tail Recursive Method

```
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;
    reverseList(&head);
    return head;
  }
private:
  void reverseList(ListNode** head) {
    if (NULL == head) return;
    reverseList(*head, NULL, head);
  }
private:
  void reverseList(ListNode* curr, ListNode* prev, ListNode** head) {
    if (NULL == curr->next) {
      *head = curr;
      curr->next = prev;
      return;
    }

    ListNode* next = curr->next;
    curr->next = prev;
    reverseList(next, curr, head);
  }
};
```

#### 辅助栈版 Stack Method

```
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (NULL == head || NULL == head->next) return head;

    stack<ListNode*> s;
    ListNode *p = head;
    while (p != NULL) {
      s.push(p);
      p = p->next;
    }

    head = s.top();
    s.pop();
    p = head;
    while (!s.empty()) {
      p->next = s.top();
      s.pop();
      p = p->next;
    }
    p->next = NULL;
    return head;
  }
};
```

Time Complexity: O(n)

Space Complexity: O(n)