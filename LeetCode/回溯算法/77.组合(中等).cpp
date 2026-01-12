#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> used(21, 0);
        vector<vector<int>> res;
        vector<int> path;
        function<void()> backtrack = [&](){
            // 终止条件
            if(path.size() == k){
                res.push_back(path);
                return;
            }
            for(int i = 1; i <= n; i++){
                if(used[i] == 0 && (path.empty() || i > path.back())){
                    used[i] = 1;
                    path.push_back(i);
                    backtrack();
                    // 回溯
                    path.pop_back();
                    used[i] = 0;
                }
            }
        };
        backtrack();
        return res;
    }

    // 优化版本：使用起始位置剪枝，避免遍历无效组合
    vector<vector<int>> combine2(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        function<void(int)> backtrack = [&](int start) {
            // 终止条件
            if(path.size() == k){
                res.push_back(path);
                return;
            }
            // 剪枝：剩余不足 k - path.size() 个数字时直接返回
            for(int i = start; i <= n - (k - path.size()) + 1; i++){
                path.push_back(i);
                backtrack(i + 1);
                path.pop_back();
            }
        };

        backtrack(1);
        return res;
    }
};