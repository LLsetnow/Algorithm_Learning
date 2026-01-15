/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。


示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：

输入：nums = [0]
输出：[[],[0]]


提示：

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    nums 中的所有元素 互不相同
思路：
    使用位运算生成所有子集
    n = nums.size()
    总共有 2^n 个子集
    每个子集可以表示为一个二进制数
    例如：nums = [1,2,3]
    000 -> []
    001 -> [1]
    010 -> [2]
    011 -> [1,2]
    100 -> [3]
    101 -> [1,3]
    110 -> [2,3]
    111 -> [1,2,3]

*/
#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> res;
            // 共 2^n 个子集
            // i 从 000 到 111
            for(int i = 0; i < (1 << n); i++){
                vector<int> path;
                // 遍历二进制数的每一位，如果为1，则添加对应的元素
                for(int j = 0; j < n; j++){
                    if(i & (1 << j)) path.push_back(nums[j]);
                }
                res.push_back(path);
            }
            return res;
        }
    };