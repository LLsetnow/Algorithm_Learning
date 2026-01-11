#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums){
            int n = nums.size();
            if(n == 1) return nums[0];
            if(n == 2) return max(nums[0], nums[1]);
            return max(rob_func(nums, 0, n - 2), rob_func(nums, 1, n - 1));
        }
        int rob_func(vector<int>& nums, int start, int end) {
            // nums 下标范围 [start, end]
            // dp 下标范围 [0, end - start]
            int n = end - start + 1;
            vector<int> dp(n, 0);
            if(n == 1) return nums[start];
            dp[0] = nums[start];
            dp[1] = max(nums[start], nums[start + 1]);
            for(int i = 2; i < n; i++){
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
            }
            return dp[n - 1];
        }
    };

int main(){
    Solution s;
    vector<int> nums = {1,2,1,1};
    cout << s.rob(nums) << endl;
}