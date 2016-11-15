### 第n个Magic Number

A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….

Write a function to find the n’th Magic number.

magic numbers can be represented as 001, 010, 011, 100, 101, 110 etc, where 001 is 0*pow(5,3) + 0*pow(5,2) + 1*pow(5,1). So basically we need to add powers of 5 for each bit set in given integer n.

```
int nthMagicNo(int n) {
  int pow = 1, answer = 0;

  while (n) {
    pow = pow * 5;

    if (n & 1) answer += pow;
    n >>= 1;
  }
  return answer;
}
```

Note: 有快速矩阵乘法？