// O(n(logn)^2)，仍需优化，速度不够快
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cfloat>
using namespace std;

struct Point {
  float x, y;
  Point(float xx, float yy) : x(xx), y(yy) {}
};

bool compareX(const Point& a, const Point& b) {
  return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
  return a.y < b.y;
}

inline double dist(const Point& a, const Point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) +
              (a.y - b.y) * (a.y - b.y));
}

class Solution {
public:
  double findClosestPair(vector<Point>& points) {
    if (points.empty() || points.size() == 1) return -1;
    sort(points.begin(), points.end(), &compareX);
    return findClosestPair(points, 0, points.size() - 1);
  }
private:
  double findClosestPair(vector<Point>& points, int l, int r) {
    if (r - l <= 3) return bruteForce(points, l, r);

    int mid = l + (r-l)/2;
    Point midPoint = points[mid];

    double dl = findClosestPair(points, l, mid);
    double dr = findClosestPair(points, mid + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = l; i <= r; i++)
      if (fabs(points[i].x - midPoint.x) < d)
        strip.push_back(points[i]);
    return min(d, stripClosest(strip, d));
  }
  double stripClosest(vector<Point> strip, double d) {
    double d_min = d;
    sort(strip.begin(), strip.end(), compareY);
    int n = strip.size();
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n && (strip[j].y - strip[i].y) < d_min; ++j)
        d_min = min(d_min, dist(strip[i], strip[j]));
    return d_min;
  }
  double bruteForce(vector<Point>& points, int l, int r) {
    double d_min = DBL_MAX;
    for (int i = l; i <= r; i++)
      for (int j = i + 1; j <= r; j++)
        d_min = min(d_min, dist(points[i], points[j]));
    return d_min;
  }
};

int main()
{
  vector<Point> points1({Point(2, 3), Point(12, 30), Point(40, 50), Point(5, 1), Point(12, 10), Point(3, 4)});
  vector<Point> points2({Point(0, 0), Point(1, 1)});
  vector<Point> points3({Point(-1.5, 0), Point(0, 0), Point(0, 1.5)});

  Solution solution;
  cout << solution.findClosestPair(points1) << endl;
  cout << solution.findClosestPair(points2) << endl;
  cout << solution.findClosestPair(points3) << endl;
  return 0;
}
