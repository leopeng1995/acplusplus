#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d\n", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// %lld

const int MIN_INF = -1000000000;

struct TreapNode
{
  int key, priority;
  TreapNode *left, *right;
};

/* T1, T2 and T3 are subtrees of the tree rooted with y
  (on left side) or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3 */

TreapNode *rightRotate(TreapNode *y)
{
  TreapNode *x = y->left,  *T2 = x->right;

  x->right = y;
  y->left = T2;

  return x;
}

TreapNode *leftRotate(TreapNode *x)
{
  TreapNode *y = x->right, *T2 = y->left;

  y->left = x;
  x->right = T2;

  return y;
}

TreapNode* newNode(int key)
{
  TreapNode* temp = new TreapNode;
  temp->key = key;
  temp->priority = rand()%100;
  temp->left = temp->right = NULL;
  return temp;
}

TreapNode* search(TreapNode* root, int key, int &ans)
{
  if (root == NULL) return root;
  if (root->key == key)
  {
    ans = key;
    return root;
  }

  if (root->key < key)
  {
    ans = max(ans, root->key);
    return search(root->right, key, ans);
  }

  return search(root->left, key, ans);
}

TreapNode* insert(TreapNode* root, int key)
{
  if (!root) return newNode(key);

  if (key <= root->key)
  {
    root->left = insert(root->left, key);

    if (root->left->priority > root->priority)
      root = rightRotate(root);
  }
  else
  {
    root->right = insert(root->right, key);

    if (root->right->priority > root->priority)
      root = leftRotate(root);
  }
  return root;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T, k;
  char c[2];
  sc(T);
  srand(time(NULL));
  struct TreapNode *root = NULL;
  while (T--)
	{
    scanf("%s%d", c, &k);
    if (strcmp(c, "I") == 0)
      root = insert(root, k);
    else
    {
      int ans = MIN_INF;
      search(root, k, ans);
      printf("%d\n", ans);
    }
	}
  return 0;
}
