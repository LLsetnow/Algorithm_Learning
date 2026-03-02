/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30400
 *
 * [509] 斐波那契数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // 该方法代码简洁，但时间复杂度高 O(2^n) (n为二叉树层高，也是目标计算值，冗余计算较多)
    int fib2(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    /*
        带备忘录的递归解法：
            对于斐波那契数列问题，我们需要一个备忘录记录子问题 f(x) 的值，
            其中 x 是一个非负整数，所以一般用一个一维数组 memo 充当备忘录就可以了，
            让 memo[x] 存储子问题 f(x) 的返回值。
    */
   int fib(int n) {
    // 备忘录全初始化为 -1
    // 因为斐波那契数肯定是非负整数，所以初始化为特殊值 -1 表示未计算

    // 因为数组的索引从 0 开始，所以需要 n + 1 个空间
    // 这样才能把 `f(0) ~ f(n)` 都记录到 memo 中
    vector<int> memo(n + 1, -1);

    // 进行带备忘录的递归
    return dp(memo, n);
    }

    // 带着备忘录进行递归
    int dp(vector<int>& memo, int n) {
        // base case
        if (n == 0 || n == 1) {
            return n;
        }
        // 已经计算过，不用再计算了
        if (memo[n] != -1) {
            return memo[n];
        }
        // 在返回结果之前，存入备忘录
        memo[n] = dp(memo, n - 1) + dp(memo, n - 2);
        return memo[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

