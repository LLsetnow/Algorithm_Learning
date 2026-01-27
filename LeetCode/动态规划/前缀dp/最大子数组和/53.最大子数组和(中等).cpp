/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。


示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：

输入：nums = [1]
输出：1

示例 3：

输入：nums = [5,4,-1,7,8]
输出：23

思路:
 动态规划
 定义状态: dp[i] 表示以 nums[i] 结尾的最大子数组和
 状态转移方程: dp[i] = max(nums[i], dp[i-1] + nums[i])
 初始条件: dp[0] = nums[0]
 最终结果: max(dp[i]) (0 <= i < nums.size())

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int res = nums[0];
            vector<int> dp(n, 0);
            dp[0] = nums[0];
            for(int i = 1; i < n; i++) {
                dp[i] = max(nums[i], dp[i-1] + nums[i]);
                res = max(res, dp[i]);
            }
            return res;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
    