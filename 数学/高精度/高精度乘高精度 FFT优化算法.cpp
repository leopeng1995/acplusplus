// 算法思想：将两个高精度乘数每个数位上的数视为多项式对应的系数，
// 用o(n*log(n))的复杂度转成点值形式，再利用o(n)的复杂度相乘，最
// 后对点值进行差值，用o(n*log(n))的复杂度还原成多项式的形式，即
// 原来的形式。算法复杂度：o(n*log(n))

const int MAXN = 133015;
double ax[MAXN], ay[MAXN], bx[MAXN], by[MAXN];
char sa[MAXN >> 1], sb[MAXN >> 1];
int sum[MAXN];
int x1[MAXN], x2[MAXN];
int revv(int x, int bits)
{
  int ret = 0;
  for (int i = 0; i < bits; i++) {
    ret <<= 1;
    ret |= x & 1;
    x >>= 1;
  }
  return ret;
}

void fft(double *a, double *b, int n, bool rev) {
  int bits = 0;
  while (1 << bits < n) ++bits;
  for (int i = 0; i < n; ++i) {
    int j = revv(i, bits);
    if (i < j) swap(a[i], a[j]), swap(b[i], b[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    int half = len >> 1;
    double wmx = cos(2 * PI / len), wmy = sin(2 * PI / len);
    if (rev) wmy = -wmy;
    for (int i = 0; i < n; i += len) {
      double wx = 1, wy = 0;
      for (int j = 0; j < half; ++j) {
        double cx = a[i + j], cy = b[i + j];
        double dx = a[i + j + half], dy = b[i + j + half];
        double ex = dx * wx - dy * wy, ey = dx * wy + dy * wx;
        a[i + j] = cx + ex, b[i + j] = cy + ey;
        a[i + j + half] = cx - ex, b[i + j + half] = cy - ey;
        double wnx = wx * wmx - wy * wmy, wny = wx * wmy + wy * wmx;
        wx = wnx, wy = wny;
      }
    }
  }
  if (rev) for (int i = 0; i < n; i++) a[i] /= n, b[i] /= n;
}

int solve(int a[], int na, int b[], int nb, int ans[]) {
  int len = max(na, nb), ln;
  for(ln = 0; L(ln) < len; ++ln);
  len = L(++ln);
  for (int i = 0; i < len ; ++i) {
    if (i >= na) ax[i] = 0, ay[i] = 0;
    else ax[i] = a[i], ay[i] = 0;
  }
  fft(ax, ay, len, 0);
  for (int i = 0; i < len; ++i) {
    if (i >= nb) bx[i] = 0, by[i] = 0;
    else bx[i] = b[i], by[i] = 0;
  }
  fft(bx, by, len, 0);
  for (int i = 0; i < len; ++i) {
    double cx = ax[i] * bx[i] - ay[i] * by[i];
    double cy = ax[i] * by[i] + ay[i] * bx[i];
    ax[i] = cx, ay[i] = cy;
  }
  fft(ax, ay, len, 1);
  for (int i = 0; i < len; ++i) ans[i] = (int)(ax[i] + 0.5);
  return len;
}

string mul(string &sa,string &sb) {
  int l1,l2,l;
  int i;
  string ans;
  memset(sum, 0, sizeof(sum));
  l1 = sa.size();
  l2 = sb.size();
  for(i = 0; i < l1; i++) x1[i] = sa[l1 - i - 1]-'0';
  for(i = 0; i < l2; i++) x2[i] = sb[l2-i-1]-'0';
  l = solve(x1, l1, x2, l2, sum);
  for(i = 0; i<l || sum[i] >= 10; ++i) {  // 进位
    sum[i + 1] += sum[i] / 10;
    sum[i] %= 10;
  }
  l = i;
  while(sum[l] <= 0 && l > 0) --l; // 检索最高位
  for(i = l; i >= 0; i--) ans += sum[i] + '0'; // 倒序输出
  return ans;
}
