#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int countHousePlacements(int n) {
            vector<int> dp(n + 1, 0);
            int mod = 1e9 + 7;
            dp[0] = 1;
            dp[1] = 2;
            for(int i = 2; i <= n; i++){
                dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
            }

            int res = (int)multiply_mod(dp[n], mod);   
            return res;   
        }

        long long multiply_mod(int64_t a, int64_t MOD) {
            a %= MOD;
            
            // 使用 double 计算乘积，然后取模
            double res = (double)a * a;
            int64_t q = (int64_t)(res / MOD);  // 估计商
            int64_t result = a * a - q * MOD;
            
            // 调整结果到 [0, MOD) 范围内
            if (result < 0) result += MOD;
            if (result >= MOD) result -= MOD;
            return result;
        }
        
    };

int main(){
    Solution s;
    cout << s.countHousePlacements(1000) << endl;
}