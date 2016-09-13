// 线性同余方程：ax===b(mod m),求解x的值

// POJ1061 青蛙的约会
int64 mod(int64 a, int64 b) {
  if (a >= 0) return a%b;
  return a%b+b;
}

int64 extgcd(int64 a, int64 b) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64 r = extgcd(b, a%b);
  int64 t = x;
  x = y;
  y = t - a / b * y;
  return r;
}
