#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
  struct Node *left, *right;
  int key;
};

Node* newNode(int key) {
  Node *temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

//Node *lca(Node* root, int n1, int n2) {
//  return root;
//
//  if (root == NULL) return NULL;
//
//  if (root->key > n1 && root->key > n2)
//    return lca(root->left, n1, n2);
//
//  if (root->key < n1 && root->key < n2)
//    return lca(root->right, n1, n2);
//
//  return root;
//}

Node *lca(Node* root, int n1, int n2) {
  while (root != NULL) {
    if (root->key > n1 && root->key > n2)
      root = root->left;
    else if (root->key < n1 && root->key < n2)
      root = root->right;
    else break;
  }
  return root;
}

int main()
{
  Node *root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);

  int n1 = 10, n2 = 14;
  Node *t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);

  n1 = 14, n2 = 8;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);

  n1 = 10, n2 = 22;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);
  return 0;
}
