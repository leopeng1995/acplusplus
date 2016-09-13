// 计算凸包，输入点数组p，个数为n，输出点数组ch。函数返回凸包顶点数
// 输入不能有重复点。函数执行完之后输入点的顺序被破坏
// 如果不希望在凸包的边上有输入点，把两个 <= 改成 <
// 在精度要求高时建议用dcmp比较
int ConvexHull(Point* p, int n, Point* ch) {
  sort(p, p+n);
  int m = 0;
  for(int i = 0; i < n; i++) {
    while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n-2; i >= 0; i--) {
    while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--;
  return m;
}
