/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：

输入：nums = [1]
输出：[[1]]

*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> path;
            /*
                has[i] = 0：数字不存在
                has[i] = 1：数字存在且未使用
                has[i] = 2：数字存在且已使用
                has[0] 表示数字 -10
            */
            int has[21] = {0};
            for(auto &num : nums) has[num + 10] = 1;

            function<void()> backtrack = [&]() {
                // 数字全部使用完，保存当前路径，并终止
                if (path.size() == nums.size()) {
                    result.push_back(path);
                    return;
                }
                for (int i = 0; i < 21; i++) {
                    if (has[i] == 1) {
                        has[i] = 2;
                        path.push_back(i - 10);
                        backtrack();
                        // 回溯到上一个节点
                        path.pop_back();
                        has[i] = 1;
                    }
                }
            };

            backtrack();
            return result;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = s.permute(nums);
    for(auto &v : result){
        for(auto &i : v){
            cout << i << " ";
        }
        cout << endl;
    }

}