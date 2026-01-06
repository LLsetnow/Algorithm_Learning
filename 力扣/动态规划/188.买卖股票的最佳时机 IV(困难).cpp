#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, INT32_MIN / 2));
            dp[0][0] = 0;
            int maxPro = 0;
            for(int i = 1; i < n + 1; i++){
                int w = prices[i - 1];
                dp[i][0] = dp[i - 1][0];
                for(int j = 1; j < 2 * k + 1; j++){
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + w * (j % 2? -1 : 1));
                    maxPro = max(maxPro, dp[i][j]);
                }
            }
            return maxPro;
        }

        //空间优化
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<int> dp(2 * k + 1, INT32_MIN / 2);
            dp[0] = 0;
            int maxPro = 0;
            for(int i = 1; i < n + 1; i++){
                int w = prices[i - 1];
                for(int j = 1; j < 2 * k + 1; j++){
                    dp[j] = max(dp[j], dp[j - 1] + w * (j % 2? -1 : 1));
                    maxPro = max(maxPro, dp[j]);
                }
            }
            return maxPro;
        }
    };


int main(){
    Solution s;
    vector<int> prices = {2,4,1};
    cout << s.maxProfit(2, prices) << endl;
    return 0;
}