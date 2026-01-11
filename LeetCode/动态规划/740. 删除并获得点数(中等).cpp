#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            int n = nums.size();
            int maxNumber = 0;
            vector<int> count(10001, 0);
            // 统计每个数字出现的次数
            for(int i = 0; i < n; i++){
                count[nums[i]]++;
                if(nums[i] > maxNumber) {
                    maxNumber = nums[i];
                }
            }
            vector<int> dp(maxNumber + 1, 0);
            dp[0] = 0;
            dp[1] = count[1];
            for(int i = 2; i < maxNumber + 1; i++){
                dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
            }
            return dp[maxNumber];
        }
    };

int main(){
    Solution s;
    vector<int> nums = {2,2,3,3,3,4};
    cout << s.deleteAndEarn(nums) << endl;
}