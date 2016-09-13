// 适用于题目中给的n不是很多，但是n特别大的情况
#include <stdio.h>
int main()
{
  __int64 a[100], num, n;
  while(scanf("%I64d",&n)!=EOF) {
    num = 0;
    for(int i = 2;i * i <= n; ++i) {
      if(n%i==0) {
        a[num++] = i;
        while(n % i == 0)
          n=n/i;
      }
    }
    if(n > 1) a[num++] = n;
    for(int i = 0; i < num; ++i)
      printf("%I64d ",a[i]);
    printf("\n");
  }
  return 0;
}

// 适用于题目中给的n个数比较多的，但是n不是很大的情况
// 注：以下代码有瑕疵
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100000 + 10;
int visited[MAXN];
vector<int>a[MAXN];

void init()
{
  int i,j;
  for(i = 0; i < MAXN; ++i)
    a[i].clear();//vector的清空
  memset(visited,0,sizeof(visited));
  for(i = 2; i <= 100000; ++i)
  {
    if(visited[i] == 0) // i是素数这是可以保证的
    {
      a[i].push_back(i);
      for(j = i + i; j <= 100000; j += i) // 筛选素数，其实这种方法没以前那种素数法快，但是这里用来求一个数的质因子就比较好了
      {
        visited[j]=1;
        a[j].push_back(i);
      }
    }
  }
}

int main()
{
  int i,j;
  init();
  for(i = 0; i <= 50; ++i)
  {
    printf("%d:", i);
    for(j = 0; j < (int)a[i].size(); ++j)
      printf("%d ",a[i][j]);
    printf("\n");
  }
  return 0;
}
