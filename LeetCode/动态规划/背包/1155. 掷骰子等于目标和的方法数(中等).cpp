/*
这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。

给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 k^n 种方式），
使得骰子面朝上的数字总和等于 target。

由于答案可能很大，你需要对 109 + 7 取模。


示例 1：

输入：n = 1, k = 6, target = 3
输出：1
解释：你掷了一个有 6 个面的骰子。
得到总和为 3 的结果的方式只有一种。

示例 2：

输入：n = 2, k = 6, target = 7
输出：6
解释：你掷了两个骰子，每个骰子有 6 个面。
有 6 种方式得到总和为 7 的结果: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1。

示例 3：

输入：n = 30, k = 30, target = 500
输出：222616187
解释：返回的结果必须对 109 + 7 取模。

 
提示：

    1 <= n, k <= 30
    1 <= target <= 1000



*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class Solution {
    public:
        int numRollsToTarget(int n, int k, int target) {
            const int MOD = 1e9 + 7;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            function<int(int, int)> dfs = [&](int n, int target){
                if(target < 0 || n * k < target || n > target)
                    return 0;
                if(n == 0)
                    return (int)(target == 0);
                if(dp[n][target] != -1)
                    return dp[n][target];
                int res = 0;
                for(int x = 1; x <= min(k, target); x++){
                    res = (res + dfs(n - 1, target - x)) % MOD;
                }
                return dp[n][target] = res;
            };

            return dfs(n, target);
        }
    };
int main(){
    Solution sol;
    cout << sol.numRollsToTarget(1, 6, 3) << endl;
    cout << sol.numRollsToTarget(2, 6, 7) << endl;
    cout << sol.numRollsToTarget(30, 30, 500) << endl;
    return 0;
}