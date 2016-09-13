#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *left, *right, *parent;
  int key;
};

Node *newNode(int item) {
  Node *temp = new Node;
  temp->key = item;
  temp->parent = temp->left = temp->right = NULL;
  return temp;
}

Node *insert(Node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key) {
    node->left = insert(node->left, key);
    node->left->parent = node;
  } else if (key > node->key) {
    node->right = insert(node->right, key);
    node->right->parent = node;
  }

  return node;
}

int depth(Node *node) {
  int d = -1;
  while (node) {
    ++d;
    node = node->parent;
  }
  return d;
}

Node *LCA(Node *n1, Node *n2) {
  int d1 = depth(n1), d2 = depth(n2);
  int diff = d1 - d2;

  if (diff < 0) {
    Node * temp = n1;
    n1 = n2;
    n2 = temp;
    diff = -diff;
  }

  while (diff--)
    n1 = n1->parent;

  while (n1 && n2) {
    if (n1 == n2)
      return n1;
    n1 = n1->parent;
    n2 = n2->parent;
  }

  return NULL;
}

// Driver method to test above functions
int main(void)
{
  Node * root = NULL;

  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);

  Node *n1 = root->left->right->left;
  Node *n2 = root->right;

  Node *lca = LCA(n1, n2);
  printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key);

  return 0;
}
