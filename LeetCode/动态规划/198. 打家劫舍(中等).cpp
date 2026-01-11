#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, 0);
            if(n == 1) return nums[0];
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2; i < n; i++){
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            return dp[n - 1];

        }
    };

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.rob(nums) << endl;
}