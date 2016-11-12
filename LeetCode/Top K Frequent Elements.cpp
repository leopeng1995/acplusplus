#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
  int val;
  int cnt;
  Node(int v) : val(v), cnt(1) {}
};

bool operator<(const Node& lhs, const Node& rhs) {
  return lhs.cnt < rhs.cnt;
}

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    if (nums.empty() || k == 0) return ans;
    priority_queue<Node> pq;
    unordered_map<int, Node> dict;
    for (auto it = nums.begin(); it != nums.end(); it++) {
      if (dict.find(*it) == dict.end()) {
        Node n(*it);
        dict.insert(std::pair<int, Node>(*it, n));
      } else {
        auto it2 = dict.find(*it);
        (it2->second).cnt += 1;
      }
    }
    for (auto it = dict.begin(); it != dict.end(); it++) pq.push(it->second);
    for (int i = 0; i < k; i++) {
      Node n = pq.top();
      ans.push_back(n.val);
      pq.pop();
    }
    return ans;
  }
};

std::ostream& operator<<(std::ostream& stream, vector<int>& ans) {
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return stream;
}

int main()
{
  vector<int> nums1({1, 1, 1, 2, 2, 3});
  vector<int> nums2({4, 1, -1, 2, -1, 2, 3});

  Solution solution;

  vector<int> ans1 = solution.topKFrequent(nums1, 2);
  vector<int> ans2 = solution.topKFrequent(nums2, 2);

  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}