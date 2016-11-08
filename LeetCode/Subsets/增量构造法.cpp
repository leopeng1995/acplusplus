// 增量构造，从1到n的子集集合
void print_subset(int n, int* A, int cur) {
  for (int i = 0; i < cur; i++) printf("%d ", A[i]);	// 打印当前集合
  printf("\n");
  int s = cur ? A[cur - 1] + 1 : 0;	// 确定当前元素的最小可能值
  for (int i = s; i < n; i++) {
    A[cur] = i;
    print_subset(n, A, cur + 1);
  }
}