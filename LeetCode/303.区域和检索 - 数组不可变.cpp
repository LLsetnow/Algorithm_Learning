/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30400
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
public:
    vector<int> s;
    NumArray(vector<int>& nums) {
        s.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return s[right + 1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]\n
// @lcpr case=end

 */

