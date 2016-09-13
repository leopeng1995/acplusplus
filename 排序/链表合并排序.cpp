#include <cstdio>
#include <cstdlib>

struct node {
  int data;
  struct node* next;
};

struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);

void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;

  if ((head == NULL) || (head->next == NULL)) return;

  FrontBackSplit(head, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *headRef = SortedMerge(a, b);
}

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  if (a == NULL) return(b);
  else if (b==NULL) return(a);

  if (a->data <= b->data) {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source == NULL || source->next == NULL) {
    *frontRef = source;
    *backRef = NULL;
  }
  else {
    slow = source;
    fast = source->next;

    while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

void printList(struct node *node) {
  while(node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main()
{
  struct node* res = NULL;
  struct node* a = NULL;

  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  MergeSort(&a);

  printf("Sorted Linked List is:\n");
  printList(a);

  return 0;
}
