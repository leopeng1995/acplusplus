#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_BITS = 32;
class Solution {
public:
  Solution() {
    bases[0] = 1;
    for (int i = 1; i < 32; i++)
      bases[i] = bases[i - 1] * 2;
  }
public:
  uint32_t reverseBits(uint32_t n) {
    static int bits[MAX_BITS] = {0};
    memset(bits, 0, sizeof(bits));

    int mask = 1;
    uint32_t ret = 0;
    for (int i = 0; i < MAX_BITS; ++i)
      if (n & (mask << i))
        ret += bases[MAX_BITS - i -1];
    return ret;
  }
private:
  uint32_t bases[32];
};

int main()
{
  uint32_t u1 = 0;
  uint32_t u2 = 0xFFFFFFFF;
  uint16_t u3 = 43261596;

  Solution solution;
  cout << solution.reverseBits(u3) << endl;
  return 0;
}
