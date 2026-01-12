#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
public:

    // 优化版本：使用起始位置剪枝，避免遍历无效组合
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();

        function<void(int)> backtrack = [&](int start) {
            // 终止条件:无
            // 每次回溯完，就会产生一个新的合法路径
            res.push_back(path);

            // 选择当前元素及之后的元素
            for(int i = start; i < n; i++){
                path.push_back(nums[i]);
                backtrack(i + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};