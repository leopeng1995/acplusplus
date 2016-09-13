#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 100000;
int A[MAX_N], P[MAX_N];

// 生成1~n的排列
void print_permutation(int n, int* A, int cur) {
	if (cur == n) {
		for (int i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for (int i = 1; i <= n; i++) {
		int ok = 1;
		for (int j = 0; j < cur; j++)
			if (A[j] == i) ok = 0;
		if (ok) {
			A[cur] = i;
			print_permutation(n, A, cur+1);
		}
	}
}

// 生成可重集的排列
void print_permutation(int n, int* P, int* A, int cur) {
  if (cur == n) {
		for (int i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for (int i = 0; i < n; i++)
    if (!i || P[i] != P[i - 1])
    {
      int c1 = 0, c2 = 0;
      for (int j = 0; j < cur; j++) if (A[j] == P[i]) c1++;
      for (int j = 0; j < n; j++) if (A[i] == P[j]) c2++;
      if (c1 < c2) {
        A[cur] = P[i];
        print_permutation(n, P, A, cur+1);
      }
    }
}

int main()
{
  for (int i = 0; i < 3; i++) P[i] = 1;
  for (int i = 0; i < 3; i++) A[i] = i + 1;
  //print_permutation(3, A, 0);
  print_permutation(3, P, A, 0);
  return 0;
}
