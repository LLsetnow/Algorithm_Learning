/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

 

提示：

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums 是一个非递减数组
    -109 <= target <= 109



*/

#include <vector>   
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int i = 0;
            int j = nums.size() - 1;
            int mid = 0;
            // 先快速找到其中一个target
            while(i <= j){
                mid = (i + j) / 2;
                if(nums[mid] == target) break;
                if(nums[mid] < target) i = mid + 1;
                if(nums[mid] > target) j = mid - 1;
            }
            if(i > j) return {-1, -1};
            i = j = mid;
            while(i >= 0 && nums[i] == target) i--;
            if(i < 0 || nums[i] != target) i++;
            while(j < (int)nums.size() && nums[j] == target) j++;
            if(j >= (int)nums.size() || nums[j] != target) j--;
            return {i, j};
        }
    };


int main(){
    system("clear");
    vector<int> nums = {1,2,3,3,3,3,4,5,9};
    int target = 3;
    Solution s;
    vector<int> result = s.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}