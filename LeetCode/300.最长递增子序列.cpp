/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30400
 *
 * [300] 最长递增子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // 自底向上
    int lengthOfLIS(vector<int>& nums) {
        // 状态定义：以 nums[i] 这个数结尾的最长递增子序列的长度
        int n = nums.size();
        int res = 1;
        vector<int> dp(n, 1);
        // 转移方程，找前i-1中，nums[k] < nums[i] 且 max(nums[k]+1)
        for(int i = 1; i < n; i++){
            for(int k = 0; k < i; k++){
                if(nums[k] < nums[i])
                    dp[i] = max(dp[i], dp[k] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

