// Hint: 需要去掉所有空格后缀
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        if (s.at(s.size() - 1) == ' ') {
            auto it = s.find_last_not_of(' ');
            s = s.substr(0, it + 1);
        }
        auto found = s.find_last_of(" ");
        return s.size() - 1 - found;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLastWord("Hello World") << endl;
    cout << solution.lengthOfLastWord("Hello ") << endl; // 5
    cout << solution.lengthOfLastWord("Hello Beijing ") << endl;
    cout << solution.lengthOfLastWord("Hello Fuckoff") << endl;
    cout << solution.lengthOfLastWord("b   a    ") << endl; // 1 
    cout << solution.lengthOfLastWord("") << endl;
    cout << solution.lengthOfLastWord("               ") << endl;
    return 0;
}