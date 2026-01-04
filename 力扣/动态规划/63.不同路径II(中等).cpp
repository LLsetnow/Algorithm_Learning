#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(j == 0)
                    dp[i][j] = dp[i-1][j];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        print_dp(dp);
        return dp[m-1][n-1];
    }

    void print_dp(vector<vector<int>>& dp) {
        for(auto& row : dp) {
            for(auto& col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0},{1,1},{0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}