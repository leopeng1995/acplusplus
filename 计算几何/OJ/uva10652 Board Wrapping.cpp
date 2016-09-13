#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

//const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long int64;	// %lld

struct Point {
  double x, y;
  Point(double x = 0, double y = 0): x(x), y(y) { } // 构造函数，方便代码编写
};

typedef Point Vector; // 从程序实现上，Vector只是Point的别名

// 向量+向量=向量，点+向量=点
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
// 点-点=向量
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
// 向量*数=向量
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
// 向量/数=向量
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y);
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }

// rad是弧度
Vector Rotate(Vector A, double rad) {
  return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

// 作为特殊情况，下面的函数计算向量的单位法线，即左转90°以后把长度归一化
// 调用前请确保A不是零向量
Vector Normal(Vector A) {
  double L = Length(A);
  return Vector(-A.y / L, A.x / L);
}

// 求直线交点
// 调用前请确保两条直线P+tv和Q+tw有唯一交点，当且仅当Cross(v,w)非0
// 在精度要求极高的情况下，可以考虑自定义分数类
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
  Vector u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}

// 点到直线的距离
double DistanceToLine(Point P, Point A, Point B) {
  Vector v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1);  // 如果不取绝对值，得到的是有向距离
}

double DistanceToSegment(Point P, Point A, Point B) {
  if(A == B) return Length(P - A);
  Vector v1 = B - A, v2 = P - A, v3 = P - B;
  if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}

// 点在直线上的投影
Point GetLineProjection(Point P, Point A, Point B) {
  Vector v = B - A;
  return A + v * (Dot(v, P - A) / Dot(v, v));
}

// 直线相交判定（不允许在端点处相交）
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
          c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

// 如果多边形是凸的，可以从第一个顶点出发把凸多边形分成n-2个三角形
double ConvexPolygonArea(Point* p, int n) {
  double area = 0;
  for(int i = 1; i < n - 1; ++i)
    area += Cross(p[i] - p[0], p[i+1] - p[0]);
  return area / 2;
}

// 多边形的有向面积
double PolygonArea(Point* p, int n) {
  double area = 0;
  for(int i = 1; i < n - 1; ++i)
    area += Cross(p[i] - p[0], p[i+1] - p[0]);
  return area / 2;
}

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

// 角度转换成弧度
double torad(double deg) {
  return deg/180 * acos(-1);  // acos(-1)就是PI
}

const int MAX_N = 2500;

int main()
{
  freopen("in.txt", "r", stdin);
  int T;
  Point P[MAX_N], ch[MAX_N];
  sc(T);
  while(T--)
  {
    int n, pc = 0;
    double area1 = 0;
    sc(n);
    for (int i = 0; i < n; ++i)
    {
      double x, y, w, h, j, ang;
      scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &h, &j);
      Point o(x, y);
      ang = -torad(j);  // 顺时针旋转
      P[pc++] = o + Rotate(Vector(-w/2,-h/2), ang);
      P[pc++] = o + Rotate(Vector(w/2,-h/2), ang);
      P[pc++] = o + Rotate(Vector(-w/2,h/2), ang);
      P[pc++] = o + Rotate(Vector(w/2,h/2), ang);
      area1 += w*h; // 累加模板总面积
    }
    int m = ConvexHull(P, pc, ch);
    double area2 = PolygonArea(ch, m);
    printf("%.1lf %%\n", area1*100/area2);
  }
  return 0;
}
