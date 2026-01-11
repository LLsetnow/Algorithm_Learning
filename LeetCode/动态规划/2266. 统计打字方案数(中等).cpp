#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int countTexts(string pressedKeys) {
            int n = pressedKeys.size();
            const int mod = 1e9 + 7;
            vector<long long> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;
            for(int i = 2; i <= n; i++){
                int idx = i - 1;
                if(pressedKeys[idx] != pressedKeys[idx - 1])
                    dp[i] = dp[i - 1];
                else if((pressedKeys[idx] == '7' || pressedKeys[idx] == '9') && idx >= 3 
                        && pressedKeys[idx] == pressedKeys[idx - 1]  
                        && pressedKeys[idx] == pressedKeys[idx - 2]  
                        && pressedKeys[idx] == pressedKeys[idx - 3]) 
                    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4]) % mod;
                else if(idx >= 2 && pressedKeys[idx] == pressedKeys[idx - 1]  
                        && pressedKeys[idx] == pressedKeys[idx - 2])
                    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
                else if(pressedKeys[idx] == pressedKeys[idx - 1])
                    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            }
            print_dp(dp);
            return dp[n];
        }

        void print_dp(vector<long long>& dp){
            for(auto& i : dp){
                cout << i << " ";
            }
            cout << endl;
        }
    };

int main(){

    Solution s;

    cout << s.countTexts("222222222222222222222222222222222222") << endl;

    return 0;

}