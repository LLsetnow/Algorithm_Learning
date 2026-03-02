/*
 * @lc app=leetcode.cn id=354 lang=cpp
 * @lcpr version=30400
 *
 * [354] 俄罗斯套娃信封问题
 */
#include <bits/stdc++.h>
using namespace std;
// 相当于 找长宽两个维度的最长升序子序列
// 将信封先按照宽度升序排序，确保宽度可以嵌套
// 再将相同宽的信封，按照长度降序排序
// 最后从长度列表中找到最长升序子序列即可
// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });
        // 对高度数组寻找 LIS
        vector<int> height(n);
        for (int i = 0; i < n; i++)
            height[i] = envelopes[i][1];

        return lengthOfLIS(height);
    }
    
    // 返回 nums 中 LIS 的长度
    int lengthOfLIS(vector<int>& nums) {
        int piles = 0, n = nums.size();
        vector<int> top(n);
        for (int i = 0; i < n; i++) {
            // 要处理的扑克牌
            int poker = nums[i];
            int left = 0, right = piles;
            // 二分查找插入位置
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles) piles++;
            // 把这张牌放到牌堆顶
            top[left] = poker;
        }
        // 牌堆数就是 LIS 长度
        return piles;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [[5,4],[6,4],[6,7],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */

