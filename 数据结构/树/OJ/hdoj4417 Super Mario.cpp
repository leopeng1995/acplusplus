// 划分树
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)

const int MAX_L = 30;
const int MAX_N = 100000 + 5;

int tree[MAX_L][MAX_N];
int sorted[MAX_N];
int toleft[MAX_L][MAX_N];

void build(int l, int r, int dep)
{
  if (l == r) return;
  int mid = (l+r)>>1;
  int same = mid-l+1;

  for (int i = l; i <= r; i++) if (tree[dep][i] < sorted[mid]) same--;
  int lpos = l;
  int rpos = mid + 1;
  for (int i = l; i <= r; i++)
  {
    if (tree[dep][i] < sorted[mid])
      tree[dep+1][lpos++] = tree[dep][i];
    else if (tree[dep][i] == sorted[mid] && same > 0)
    {
      tree[dep+1][lpos++] = tree[dep][i];
      same--;
    }
    else tree[dep+1][rpos++] = tree[dep][i];
    toleft[dep][i] = toleft[dep][l-1] + lpos - l;
  }
  build(l, mid, dep+1);
  build(mid+1, r, dep+1);
}

int query(int L, int R, int l, int r, int dep, int k)
{
  if (l == r) return tree[dep][l];

  int mid = (L+R)>>1;
  int cnt = toleft[dep][r] - toleft[dep][l-1];
  if (cnt >= k)
  {
    int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
    int newr = newl + cnt - 1;
    return query(L, mid, newl, newr, dep+1, k);
  }
  else
  {
    int newr = r + toleft[dep][R] - toleft[dep][r];
    int newl = newr - (r - l - cnt);
    return query(mid+1, R, newl, newr, dep+1, k-cnt);
  }
}

int solve(int n, int s, int t, int h)
{
  int ans = 0;
  int l = 1;
  int r = (t - s) + 1;
  int mid;
  while (l <= r)
  {
    mid = (l+r)>>1;
    int temp = query(1, n, s, t, 0, mid);
    if (temp <= h)
    {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  return ans;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int T, n, m, kase = 0;
  sc(T);
  while (T--)
  {
    sc2(n, m);
    for (int i = 1; i <= n; i++)
    {
      sc(tree[0][i]);
      sorted[i] = tree[0][i];
    }
    sort(sorted+1, sorted+n+1);
    build(1, n, 0);
    printf("Case %d:\n", ++kase);
    while (m--)
    {
      int L, R, h;
      sc3(L, R, h);
      printf("%d\n", solve(n, L+1, R+1, h));
    }
  }
  return 0;
}
