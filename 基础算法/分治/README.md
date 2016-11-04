### 分治法 Divide and Conquer

Divide and Conquer is an algorithmic paradigm. A typical Divide and Conquer algorithm solves a problem using following three steps.

1. _Divide_: Break the given problem into subproblems of same type.
2. _Conquer_: Recursively solve these subproblems
3. _Combine_: Appropriately combine the answers.

以下是一些以分治法为基础的算法或使用分治法解决的问题。

1. Binary Search，二分搜索。
2. Quicksort，快速排序。
3. Merge Sort，归并排序。
4. Closest Pair of Points，平面最近点对。
5. Strassen's Algorithm，Strassen矩阵乘法。
6. Cooley-Tukey Fast Fourier Transform (FFT) algorithm，快速傅里叶变换。
7. Karatsuba algorithm for fast multiplication，快速乘法。

#### Divide and Conquer (D & C) vs Dynamic Programming (DP)

Both paradigms (D & C and DP) divide the given problem into subproblems and solve subproblems. How to choose one of them for a given problem? Divide and Conquer should be used when same subproblems are not evaluated many times. Otherwise Dynamic Programming or Memoization should be used. For example, Binary Search is a Divide and Conquer algorithm, we never evaluate the same subproblems again. On the other hand, for calculating nth Fibonacci number, Dynamic Programming should be preferred.

简而言之，就是分治法适用于子问题不需要重复计算多次的情况，而动态规划适用于子问题会使用或计算多次的情况。