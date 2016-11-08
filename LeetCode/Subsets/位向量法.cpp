void print_subset(int n, int* B, int cur) {
  if (cur == n) {
    for (int i = 0; i < cur; i++)
      if (B[i]) printf("%d ", i);
    printf("\n");
    return;
  }
  B[cur] = 1; // 选第cur个元素
  print_subset(n, B, cur + 1);
  B[cur] = 0; // 不选第cur个元素
  print_subset(n, B, cur + 1);
}

void print_subset(int n, int* B, int* nums, int cur) {
  if (cur == n) {
    for (int i = 0; i < cur; i++)
      if (B[i]) printf("%d ", nums[i]);
    printf("\n");
    return;
  }
  B[cur] = 1; // 选第cur个元素
  print_subset(n, B, nums, cur + 1);
  B[cur] = 0; // 不选第cur个元素
  print_subset(n, B, nums, cur + 1);
}