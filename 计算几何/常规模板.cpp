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

// 角度转换成弧度
double torad(double deg) {
  return deg/180 * acos(-1);  // acos(-1)就是PI
}