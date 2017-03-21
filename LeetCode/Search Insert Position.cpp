//#include <bits/stdc++.h>
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
#include <climits>
#include <cfloat>
using namespace std;

#define SCi(n) scanf("%d", &n)
#define SC2i(n,m) scanf("%d%d", &n, &m)
#define SC3i(n,m,t) scanf("%d%d%d", &n, &m, &t)
#define SCf(n) scanf("%f", &n)
#define SC2f(n,m) scanf("%f%f", &n, &m)
#define SC3f(n,m,t) scanf("%f%f%f", &n, &m, &t)
#define SCd(n) scanf("%lf", &n)
#define SC2d(n,m) scanf("%lf%lf", &n, &m)
#define SC3d(n,m,t) scanf("%lf%lf%lf", &n, &m, &t)
#define SCs(s) scanf("%s", s)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define sc(n) scanf("%d", &n)
#define sc2(n,m) scanf("%d%d", &n,&m)
#define sc3(n,m,t) scanf("%d%d%d",&n,&m,&t)
#define mset0(arr) memset(arr, 0, sizeof(arr))
#define L(x) (1 << (x))
#define INF 0xffffff
#define lowbit(x) x&(-x)

#define DEBUG_PRINT_ARRAY(array) for (int i = 0; i < n; ++i) printf("%d ", array[i])
#define DEBUG_PRINT_MATRIX(matrix, n) for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]); printf("\n"); }
#define DEBUG_PRINT_MATRIX2(matrix, n, m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) printf("%d ", matrix[i][j]); printf("\n"); }

const double eps = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;
typedef long long LL;
typedef long long int64;	// %lld

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    return searchInsert(nums, 0, nums.size() - 1, target);
  }
private:
  int searchInsert(vector<int>& nums, int left, int right, int target) {
    int L = left, R = right;
    while (L <= R) {
      int mid = L + (R - L) / 2;
      if (target < nums[mid]) R = mid - 1;
      else if (target > nums[mid]) L = mid + 1;
      else return mid;
    }
    return L;
  }
};

int main()
{
  //freopen("in.txt", "r", stdin);
  Solution solution;
  vector<int> nums1({1, 3, 5, 6}); int target1 = 5;
  vector<int> nums2({1, 3, 5, 6}); int target2 = 2;
  vector<int> nums3({1, 3, 5, 6}); int target3 = 7;
  vector<int> nums4({1, 3, 5, 6}); int target4 = 0;
  cout << solution.searchInsert(nums1, target1) << endl;
  cout << solution.searchInsert(nums2, target2) << endl;
  cout << solution.searchInsert(nums3, target3) << endl;
  cout << solution.searchInsert(nums4, target4) << endl;
  return 0;
}
