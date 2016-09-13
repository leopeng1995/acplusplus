// HDOJ3068 最长回文子串
// Manacher算法 - O(n)

const int MAXN = 110000 + 10;
char b[MAXN], a[MAXN<<1];
int p[MAXN<<1];

int main()
{
  freopen("in.txt", "r", stdin);
  int i, n, id, MaxL, MaxId;
  while (scanf("%s", &b[1]) != EOF)
  {
    MaxL = MaxId = 0;
    for (i = 1; b[i] != '\0'; ++i)
    {
      a[(i<<1)] = b[i];
      a[(i<<1) + 1] = '#';
    }
    a[0] = '?'; a[1] = '#';
    n = (i<<1) + 2; a[n] = 0;
    MaxId = MaxL = 0;
    for (i = 1; i < n; ++i)
    {
      if (MaxId > i) p[i] = min(p[2 * id - i], MaxId - i);
      else p[i] = 1;

      while (a[i + p[i]] == a[i - p[i]]) ++p[i];

      if (p[i] + i > MaxId)
      {
        MaxId = p[i] + i;
        id = i;
      }
      if (p[i] > MaxL) MaxL = p[i];
    }
    printf("%d\n", MaxL - 1);
  }
  return 0;
}
