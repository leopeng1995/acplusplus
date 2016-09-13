// 树状数组用于区间信息的维护与查询
// 给定一个n个元素的数组A1,A2,...An
// Query(L,R)： 计算AL+A(L+1)+...+AR
// Add(x,d): 让Ax增加d

int A[MAX_N];
int BIT[MAX_N];

int sum(int x) {
  int ret = 0;
  for (; x; ret += BIT[x], x -= lowbit(x));
  return ret;
}

int query(int L, int R) {
  return sum(R) - sum(L-1);
}

int query(int x) {
  int ret = 0;
  for (; x; ret += BIT[x], x -= lowbit(x));
  return ret;
}

void modify(int x, int d) {
  for (; x <= n; BIT[x] += d; x += lowbit(x));
}

// 先把A和C数组清空，然后执行n次add操作
// 时间复杂度：O(nlogn)
void init(int n) {
  mset0(A);
  mset0(BIT);
}
