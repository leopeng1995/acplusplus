#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canConstruct(string& ransomNote, string& magazine) {
    if (ransomNote.empty()) return true;
    if (magazine.empty()) return false;

    unordered_map<char, int> m;
    for (auto it = magazine.begin(); it != magazine.end(); it++) {
      if (m.find(*it) != m.end()) {
        m[*it] = m[*it] + 1;
      } else {
        m.insert(std::make_pair(*it, 1));
      }
    }

    for (auto it = ransomNote.begin(); it != ransomNote.end(); it++) {
      if (m.find(*it) != m.end()) {
        if (m[*it] == 0) return false;
        m[*it] -= 1;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  string ransomNote1("a"); string magazine1("b");
  string ransomNote2("aa"); string magazine2("ab");
  string ransomNote3("aa"); string magazine3("aab");

  Solution solution;
  cout << solution.canConstruct(ransomNote1, magazine1) << endl;
  cout << solution.canConstruct(ransomNote2, magazine2) << endl;
  cout << solution.canConstruct(ransomNote3, magazine3) << endl;
  return 0;
}
