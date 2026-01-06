/*
给你一个下标从 0 开始的整数数组 nums ，
它表示一个班级中所有学生在一次考试中的成绩。
老师想选出一部分同学组成一个 非空 小组，
且这个小组的 实力值 最大，
如果这个小组里的学生下标为 i0, i1, i2, ... , ik ，
那么这个小组的实力值定义为 nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​] 。

请你返回老师创建的小组能得到的最大实力值为多少。

*/
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    private:
        long long max4(long long a, long long b, long long c, long long d) {
            return max(max(a, b), max(c, d));
        }
        long long min4(long long a, long long b, long long c, long long d) {
            return min(min(a, b), min(c, d));
        }
    public:
        long long maxStrength(vector<int>& nums) {
            int n = nums.size();
            vector<array<long long, 2>> dp(n);
            dp[0][0] = nums[0];
            dp[0][1] = nums[0];
            for(int i = 1; i < n; i++){
                dp[i][0] = max4(nums[i], dp[i - 1][0], dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]);
                dp[i][1] = min4(nums[i], dp[i - 1][1], dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]);
            }
            return dp[n-1][0];
        }
    };

int main(){
    Solution sol;
    vector<int> nums = {3, -1, -5, 2, 5, -9};
    long long result = sol.maxStrength(nums);
    cout << result << endl;
    return 0;
}