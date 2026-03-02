/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=30400
 *
 * [931] 下降路径最小和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //dp[i][j] 表示到达该位置的最小路径和
        vector<vector<int>> dp(row, vector<int>(col, INT32_MAX));
        // 初始化
        for(int i = 0; i < col; i++)
            dp[0][i] = matrix[0][i];
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                int left = (j == 0? 0: j - 1);
                int middle = j;
                int right = (j == col - 1? j: j + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][left]);
                dp[i][j] = min(dp[i][j], dp[i - 1][middle]);
                dp[i][j] = min(dp[i][j], dp[i - 1][right]);
                dp[i][j] += matrix[i][j];
            }
        }
        int res = INT32_MAX;
        for(int i = 0; i < col; i++){
            res = min(res, dp[row - 1][i]);
        }
        return res;
    }

    int minFallingPathSum2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        // 备忘录里的值初始化为 66666
        memo = vector<vector<int>>(n, vector<int>(n, 66666));
        for (int j = 0; j < n; j++) {
            // 终点可能在 matrix[n-1] 的任意一列
            res = min(res, dp(matrix, n - 1, j));
        }
        return res;
    }

    // 备忘录
    vector<vector<int>> memo;

    int dp(vector<vector<int>>& matrix, int i, int j) {
        // 1、索引合法性检查
        if (i < 0 || j < 0 ||
            i >= matrix.size() ||
            j >= matrix[0].size()) {

            return INT_MAX;
        }
        // 2、base case
        if (i == 0) {
            return matrix[0][j];
        }
        // 3、查找备忘录，防止重复计算
        if (memo[i][j] != 66666) {
            return memo[i][j];
        }
        // 进行状态转移
        memo[i][j] = matrix[i][j] + min({
            dp(matrix, i - 1, j),
            dp(matrix, i - 1, j - 1),
            dp(matrix, i - 1, j + 1)
        });

        return memo[i][j];
    }

};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */

