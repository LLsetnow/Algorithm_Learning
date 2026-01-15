/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。

 

示例 1：

输入：n = 2
输出：[0,1,1]
解释：
0 --> 0
1 --> 1
2 --> 10

示例 2：

输入：n = 5
输出：[0,1,1,2,1,2]
解释：
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

 

提示：

    0 <= n <= 105

思路：
    动态规划
    状态表示:dp[i] 表示i的二进制表示中1的个数
    状态转移:dp[i] = dp[i >> 1] + (i & 1);
    初始状态:dp[0] = 0

*/


#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> dp(n + 1);
            for (int i = 1; i <= n; i++) {
                dp[i] = dp[i >> 1] + (i & 1);
            }
            return dp;
        }
    };