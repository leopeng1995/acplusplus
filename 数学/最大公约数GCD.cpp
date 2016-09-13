// 辗转相除法
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// 应用：线段上格点的个数
// 是|x1-x2|和|y1-y2|的最大公约数-1

// 扩展欧几里得算法
// 求整数x和y使得ax+by=1
// 如果gcd(a,b) != 1，显然无解；反之，如果gcd(a,b) == 1，可以通过扩展原来的辗转相除法来求解
int extgcd(int a, int b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}
