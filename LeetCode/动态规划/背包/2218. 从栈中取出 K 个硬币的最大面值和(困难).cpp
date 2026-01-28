/*
一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币。

每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，
并放入你的钱包里。

给你一个列表 piles ，其中 piles[i] 是一个整数数组，
分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k ，
请你返回在 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少 。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxValueOfCoins(vector<vector<int>>& piles, int k) {
            int n = piles.size();
            // dp[i][j] 表示 从 i 个硬币栈 取出体积为 j 的最大价值之和 
            vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
            auto dfs = [&](this auto&& dfs, int i, int j){
                // 递归边界
                if(i < 0) return 0;
                // 引用
                int &res = dp[i][j];
                // 之前已经计算过这种情况
                if(res)
                    return res;
                // 初始默认不选这组物品
                res = dfs(i - 1, j);
                int v = 0; // 价值前缀和
                // w+1 表示体积
                for(int w = 0; w < min(j, (int)piles[i].size()); w++){
                    v += piles[i][w];
                    res = max(res, dfs(i - 1, j - (w+1)) + v);  
                }
                return res;
            };
            return dfs(n - 1, k);
        }
    };