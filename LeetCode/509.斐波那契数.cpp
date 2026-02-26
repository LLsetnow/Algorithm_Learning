/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30400
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    // 该方法代码简洁，但时间复杂度高 O(2^n) (n为二叉树层高，也是目标计算值，冗余计算较多)
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
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

