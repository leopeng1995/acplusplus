#include <iostream>
using namespace std;

class Singleton {
private:
  Singleton() {}
private:
  static Singleton* obj;
public:
  static Singleton* getInstance() {
    if (NULL == obj)
      obj = new Singleton();
    return obj;
  }
  void hello() {
    cout << "Hello world!" << endl;
  }
};
Singleton* Singleton::obj = NULL;

class Solution {
private:
  Solution() {}
  static Solution* obj;
public:
  static Solution* getInstance() {
    if (NULL == obj)
      obj = new Solution();
    return obj;
  }
};
Solution* Solution::obj = NULL;

int main()
{
  Singleton* a = Singleton::getInstance();
  a->hello();
  return 0;
}
