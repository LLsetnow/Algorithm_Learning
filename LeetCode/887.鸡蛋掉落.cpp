/*
 * @lc app=leetcode.cn id=887 lang=cpp
 * @lcpr version=30400
 *
 * [887] 鸡蛋掉落
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    // 备忘录
    vector<vector<int>> memo;

public:
    // 自底向上
    int superEggDrop(int K, int N) {
        // m 最多不会超过 N 次（线性扫描）
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        // base case:
        // dp[0][..] = 0
        // dp[..][0] = 0
        // C++ 默认初始化数组都为 0
        int m = 0;
        while (dp[K][m] < N) {
            m++;
            for (int k = 1; k <= K; k++)
                dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
        }
        return m;
    }
    // 自顶向下
    int superEggDrop2(int K, int N) {
        // m 最多不会超过 N 次（线性扫描）
        memo.resize(K + 1, vector<int>(N + 1, -666));
        return dp(K, N);
    }

    // 定义：手握 K 个鸡蛋，面对 N 层楼，最少的扔鸡蛋次数为 dp(K, N)
    int dp(int K, int N) {
        // base case
        if (K == 1) return N;
        if (N == 0) return 0;

        // 查备忘录避免冗余计算
        if (memo[K][N] != -666) {
            return memo[K][N];
        }

        // for (int i = 1; i <= N; i++) {
        //     res = min(
        //         res,
        //         max(dp(K, N - i), dp(K - 1, i - 1)) + 1
        //     );
        // }

        // 用二分搜索代替线性搜索
        int res = INT_MAX;
        int lo = 1, hi = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // 鸡蛋在第 mid 层碎了和没碎两种情况
            int broken = dp(K - 1, mid - 1);
            int not_broken = dp(K, N - mid);
            // res = min(max(碎，没碎) + 1)
            if (broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken + 1);
            }
        }
        memo[K][N] = res;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end

// @lcpr case=start
// 3\n14\n
// @lcpr case=end

 */

