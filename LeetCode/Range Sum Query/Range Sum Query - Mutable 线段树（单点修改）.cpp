#include <iostream>
#include <vector>
using namespace std;

class STNode {
private:
  int L, R;
  int nSum;
  STNode *pLeft, *pRight;
public:
  STNode(int l, int r) {
    this->L = l;
    this->R = r;
    this->pLeft = this->pRight = nullptr;
  }
  friend class NumArray;
};

class NumArray {
public:
  NumArray(vector<int> &nums) {
    if (nums.empty()) {
      root = nullptr;
      nNums = nums;
    } else {
      nNums = nums;
      root = new STNode(0, nums.size() - 1);
      root->nSum = build(root->L, root->R, root);
    }
  }
  void update(int i, int val) {
    int diff = val - nNums[i];
    if (diff != 0) {
      nNums[i] = val;
      update(i, diff, root);
    }
  }
  int sumRange(int i, int j) {
    return sumRange(i, j, root);
  }
private:
  int build(int l, int r, STNode *p) {
    if (nullptr == p) return 0;
    if (l == r) {
      p->nSum = nNums[l];
      return p->nSum;
    }

    int mid = l + (r - l) / 2;
    p->pLeft = new STNode(l, mid);
    p->pRight = new STNode(mid + 1, r);
    p->nSum = build(l, mid, p->pLeft) +
              build(mid + 1, r, p->pRight);
    return p->nSum;
  }
  void update(int i, int diff, STNode *p) {
    if (nullptr == p) return;
    if (i < p->L || i > p->R) return;
    if (i == p->L && i == p->R) {
      p->nSum += diff;
      return;
    }

    p->nSum += diff;
    update(i, diff, p->pLeft);
    update(i, diff, p->pRight);
    return;
  }
  int sumRange(int l, int r, STNode *p) {
    if (nullptr == p) return 0;
    if (l <= p->L && r >= p->R) return p->nSum;
    if (l > p->R || r < p->L) return 0;

    return sumRange(l, r, p->pLeft) +
           sumRange(l, r, p->pRight);
  }
private:
  STNode *root;
  vector<int> nNums;
};

int main()
{
//  vector<int> nums({1, 3, 5});
////  for (auto it = nums.begin(); it != nums.end(); ++it) {
////    cout << *it << ((it == nums.end() - 1) ? "\n" : " ");
////  }
//
//  NumArray numArray(nums);
//  cout << numArray.sumRange(0, 1) << endl;  // 正确
//  //cout << numArray.sumRange(1, 2) << endl;  // 正确
//  //cout << numArray.sumRange(0, 2) << endl;  // 正确
//  //cout << numArray.sumRange(2, 2) << endl;  // 正确
//
//  numArray.update(1, 10);
//  cout << numArray.sumRange(1, 1) << endl;
//  cout << numArray.sumRange(0, 1) << endl;  // 正确
//  cout << numArray.sumRange(1, 2) << endl;  // 正确
//  cout << numArray.sumRange(0, 2) << endl;  // 正确
//  //numArray.sumRange(1, 2);

  vector<int> nums({7, 2, 7, 2, 0});
  NumArray numArray(nums);
  numArray.update(4, 6);
  numArray.update(0, 2);
  numArray.update(0, 9);
  cout << numArray.sumRange(4, 4) << endl;
  numArray.update(3, 8);
  cout << numArray.sumRange(0, 4) << endl;
  numArray.update(4, 1);
  cout << numArray.sumRange(0, 3) << endl;
  cout << numArray.sumRange(0, 4) << endl;
  numArray.update(0, 4);

  return 0;
}
