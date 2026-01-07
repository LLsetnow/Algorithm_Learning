#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int countGoodStrings(int low, int high, int zero, int one) {
            vector<long long> dp(high + 1, 0);
            dp[0] = 1;
            const int mod = 1e9 + 7;
            int count = 0;
            for(int i = 1; i <= high; i++){
                if(i >= zero) dp[i] += dp[i - zero] % mod;
                if(i >= one) dp[i] += dp[i - one] % mod;
                if(i >= low) count = (count + dp[i]) % mod;
                dp[i] %= mod;
            }
            return count;
        }
    };