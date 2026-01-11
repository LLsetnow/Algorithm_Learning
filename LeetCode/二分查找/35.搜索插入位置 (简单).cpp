/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4


提示:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums 为 无重复元素 的 升序 排列数组
    -104 <= target <= 104

*/

#include <vector>   
#include <iostream>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int i = 0;
            int j = nums.size() - 1;
            // 注意这里是 <=
            while(i <= j){
                int mid = (i + j) / 2;
                if(nums[mid] == target) return mid;
                // 注意 i = mid + 1 和 j = mid - 1
                if(nums[mid] < target) i = mid + 1;
                else j = mid - 1;
            }
            // 结束循环时 
            // 若nums[mid] < target 则 i = mid + 1 刚好为插入位置
            // 若nums[mid] > target 则 i = mid 刚好为插入位置
            return i;
        }
    };


int main(){
    system("clear");
    vector<int> nums = {1,3,5,6};
    int target = 2;
    Solution s;
    int res = s.searchInsert(nums, target);
    cout << res << endl;
}