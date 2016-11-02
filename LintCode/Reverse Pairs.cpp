// 逆序对，分治法
// 修改 MergeSort，O(nlogn)
// 分治法，基于 MergeSort
#include <iostream>
#include <vector>
#include <climits>
#include <iterator>
using namespace std;

class Solution {
public:
  long long reversePairs(vector<int>& A) {
    if (A.empty() || A.size() == 1) return 0;
    return reversePairs(A, 0, A.size() - 1);
  }
private:
  long long reversePairs(vector<int>& A, int l, int r) {
    if (l == r) return 0;

    int mid = l + (r-l)/2;
    long long ans_l = reversePairs(A, l, mid);
    long long ans_r = reversePairs(A, mid + 1, r);
    long long ans = ans_l + ans_r;

    vector<int> L, R;
    for (int i = l; i <= mid; i++) L.push_back(A[i]);
    L.push_back(INT_MAX);
    for (int i = mid + 1; i <= r; i++) R.push_back(A[i]);
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for (int k = l; k <= r; k++) {
      if (L[i] <= R[j]) A[k] = L[i++];
      else {
        A[k] = R[j];
        if (L[i] != INT_MAX && R[j] != INT_MAX) {
          ans += L.size() - i - 1;
        }
        j++;
      }
    }
    return ans;
  }
};

int main()
{
  vector<int> A1({2, 4, 1, 3, 5});
  vector<int> A2({2, 4, 1});
  vector<int> A3({1, 2});
  vector<int> A4({7, 1, 3, 4});
  vector<int> A5({});
  vector<int> A6({7});

  Solution solution;
  cout << solution.reversePairs(A1) << endl;
  cout << solution.reversePairs(A2) << endl;
  cout << solution.reversePairs(A3) << endl;
  cout << solution.reversePairs(A4) << endl;
  cout << solution.reversePairs(A5) << endl;
  cout << solution.reversePairs(A6) << endl;

//  for (auto it = A1.begin(); it != A1.end(); ++it)
//    cout << *it << " ";
//  cout << endl;
  return 0;
}
