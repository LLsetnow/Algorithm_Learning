#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int climbStairs(int n, vector<int>& costs) {
            vector<int> dp(n + 1, 0);
            dp[0] = 0;
            for (int i = 1; i < n + 1; i++) {
                if (i == 1) {
                } else if (i == 2) {
                    dp[i] = min(dp[i - 1] + costs[i - 1] + 1,
                                dp[i - 2] + costs[i - 1] + 4);
                } else {
                    dp[i] = min3(dp[i - 1] + costs[i - 1] + 1,
                                 dp[i - 2] + costs[i - 1] + 4,
                                 dp[i - 3] + costs[i - 1] + 9);
                }
            }
            // print_dp(dp);
            return dp[n];
        }
    private:
        int min3(int a, int b, int c) { return min(min(a, b), c); }
    };
