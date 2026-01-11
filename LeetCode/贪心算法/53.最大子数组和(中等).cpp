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

思路：
    https://leetcode.cn/problems/maximum-subarray/solutions/2533977/qian-zhui-he-zuo-fa-ben-zhi-shi-mai-mai-abu71/
    最小前缀和
    1. 计算前缀和
    2. 计算最小前缀和
    3. 计算 当前前缀和 - 最小前缀和
    4. 记录最大的 差值
*/
#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int ans = INT32_MIN / 2;
            int min_pre_sum = 0;
            int pre_sum = 0;
            for (int x : nums) {
                pre_sum += x; // 当前的前缀和
                ans = max(ans, pre_sum - min_pre_sum); // 减去前缀和的最小值
                min_pre_sum = min(min_pre_sum, pre_sum); // 维护前缀和的最小值
            }
            return ans;
        }
    };
    

