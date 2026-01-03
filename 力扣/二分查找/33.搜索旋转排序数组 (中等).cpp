/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：

输入：nums = [1], target = 0
输出：-1

 

提示：

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    nums 中的每个值都 独一无二
    题目数据保证 nums 在预先未知的某个下标上进行了旋转
    -104 <= target <= 104

思路：
    1.先找到旋转点
    2.再常规二分查找



*/

#include <vector>   
#include <iostream>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if(nums.size() == 0) return -1;
            if(nums.size() == 1) return nums[0] == target ? 0 : -1;
            int i = 0;
            int n = nums.size();
            int j = n - 1;
            int mid = 0;
            while(i<j){
                mid = (i + j) / 2;
                // nums[mid] > nums[j] 说明旋转点在右半部分
                if(nums[mid] > nums[j]) i = mid + 1;
                // nums[mid] < nums[j] 说明旋转点在左半部分
                else j = mid;
            }
            // 坐标映射 0-n-1 -> n-i-1 -> i
            // start = i
            // nums[k] = nums[(k + start) % nums.size()]
            int start = i;
            cout << "start: " << start << endl;
            i = 0;
            j = n - 1;
            while(i <= j){
                mid = (i + j) / 2;
                if(nums[(mid + start) % n] == target) 
                    return (mid + start) % n;
                if(nums[(mid + start) % n] < target) i = mid + 1;
                if(nums[(mid + start) % n] > target) j = mid - 1;
            }
            return -1;
        }
    };


int main(){
    system("clear");
    vector<int> nums = {1, 3};
    int target = 3;
    Solution s;
    int res = s.search(nums, target);
    cout << res << endl;
    return 0;
}