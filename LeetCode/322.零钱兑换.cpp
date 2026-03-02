/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30400
 *
 * [322] 零钱兑换
 * `k` 种面值的硬币，面值分别为 `c1, c2 ... ck`，
 * 每种硬币的数量无限，再给一个总金额 `amount`，
 * 问你**最少**需要几枚硬币凑出这个金额，如果不可能凑出，
 * 算法返回 -1
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start


class Solution {
public:
    // 顺序思路
    int coinChange2(vector<int>& coins, int amount) {
        // 表示i块钱 最少由dp[i]个硬币组成
        vector<int> dp(amount + 1, 0);       
        if(amount == 0) return 0;
        for(int i = 1; i <= amount; i++){
            // 转移方程
            dp[i] = INT_MAX;
            // 当转移方程要比较N个值时，如下解决
            for(int coin : coins){
                if(i >= coin && dp[i - coin] != INT_MAX){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    // 自顶向下解法
    int coinChange(vector<int>& coins, int amount) {
        // memo[i] 表示凑出i块钱最少需要memo[i]个硬币
        vector<int> memo(amount + 1, -1);
        // dfs(i) 表示凑出i块钱，至少要dfs(i)个硬币
        function<int(int)> dfs = [&](int target){
            // 临界条件
            if(target == 0) return 0;
            if(target < 0) return INT_MAX;
            // 记忆化：已经计算过直接返回
            if(memo[target] != -1) return memo[target];

            int res = INT_MAX;
            for(int coin : coins){
                // 子问题
                int subProblem = dfs(target - coin);
                if(subProblem != INT_MAX){
                    res = min(res, subProblem + 1);
                }
            }
            return memo[target] = res;
        };
        int result = dfs(amount);
        return result == INT_MAX ? -1 : result;
    }
};



// @lc code=end



/*
// @lcpr case=start
// [1,2,5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

