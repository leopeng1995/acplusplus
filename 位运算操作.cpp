// 快速比较两个值
a ^ b == 0

// 变量置零
a ^= a;

// 翻转某些特定的位
unsigned int a, b, mask = 1 << 6;
a = 0xB1; // 10100001
b = a ^ mask; /* flip the 6th bit */

// 整数的奇偶性判断
a & 1

// 判断n是否为2的正整数幂
(!(n&(n-1))) && n

// return int !
// 设置 x 的第 ith 位为 bool
#define set_bit(x,ith,bool) ((bool)?((x)|(1<<(ith))):((x)&(~(1<<(ith)))));

//    设置 x 的从第 ith 位起连续 k 位 为bol
int set(int x,int ith,int k,int bol)
{
    while(k --)x = set_bit(x,ith+k,bol);
    return x;
}

// 快速幂算法
int Qpow(int a, int n) {
    int ans = 1;
    while(n) {
        if(n&1) ans *= a; a *= a; n >>= 1;
    }
    return ans;
}

// 取出某个数的某一位
bool get_bit(int t,int x) {
    //    在 t 中，取出第 x 位     --从零开始
    return t & (1<<(x));
}

// 取出最低位
#define lowbit(x) x & (-p)
