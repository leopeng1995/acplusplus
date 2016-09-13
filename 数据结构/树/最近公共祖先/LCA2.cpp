#include <iostream>
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

struct Node *findLCA(struct Node* root, int n1, int n2) {
  if (root == NULL) return NULL;

  if (root->key == n1 || root->key == n2)
    return root;

  Node *left_lca = findLCA(root->left, n1, n2);
  Node *right_lca = findLCA(root->right, n1, n2);

  if (left_lca && right_lca) return root;

  return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
  cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
  cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
  cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
  return 0;
}
