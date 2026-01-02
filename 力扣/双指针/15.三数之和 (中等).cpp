/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

 

提示：

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105

思路：
    3Sum 问题可以转换为 2Sum 问题，先固定一个数，然后再使用双指针法求解 2Sum 问题。
    先对数组进行排序，然后遍历数组，对于每个元素，使用双指针法求解 2Sum 问题。


    

*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int n = 0; n < (int)nums.size() - 2; n++){
            // 跳过重复的第一个元素
            if(n > 0 && nums[n] == nums[n - 1]) continue;

            int sum = -nums[n];
            int i = n + 1, j = nums.size() - 1;
            while(i < j){
                if(nums[i] + nums[j] == sum){
                    res.push_back({nums[n], nums[i], nums[j]});
                    i++;
                    j--;
                    // 跳过重复元素
                    while(i < j && nums[i] == nums[i - 1]) i++;
                    while(i < j && nums[j] == nums[j + 1]) j--;
                }else if(nums[i] + nums[j] < sum) i++;
                else j--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for(auto& triplet : result){
        for(auto& num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}