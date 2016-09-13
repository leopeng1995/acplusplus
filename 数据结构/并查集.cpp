int parents[MAX_N]; // 父亲
int ranks[MAX_N];   // 树的高度

void Init(int n) {
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int Find(int x) {
  return parents[x] != x ? parents[x] = Find(parents[x]) : x;
}

void Unite(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;

  if (ranks[x] < ranks[y]) {
    parents[x] = y;
  } else {
    parents[y] = x;
    if (ranks[x] == ranks[y]) ++ranks[x];
  }
}

bool Same(int x, int y) {
  return Find(x) == Find(y);
}
