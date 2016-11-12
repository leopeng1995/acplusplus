### Surpasser

Given an array of integers. Find the surpasser count of each element of the array. "A surpasser of an element of an array is a greater element to its right"

Ex:

Input: [2, 7, 5, 3, 0, 8, 1]

Output: [4, 1, 1, 1, 2, 0, 0]

朴素暴力法。

从右往左遍历 + 二分查找。

位向量，求1的个数。