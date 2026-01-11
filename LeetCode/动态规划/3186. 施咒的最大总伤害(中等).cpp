/*
一个魔法师有许多不同的咒语。

给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。

已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i] + 1 或者 power[i] + 2 的咒语。

每个咒语最多只能被使用 一次 。

请你返回这个魔法师可以达到的伤害值之和的 最大值 。

 

示例 1：

输入：power = [1,1,3,4]

输出：6

解释：

可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。

示例 2：

输入：power = [7,1,6,6]

输出：13

解释：

可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。

*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumTotalDamage(vector<int>& power) {
            unordered_map<int, int> count;
            int max_power = 0;
            for(auto &p : power){
                count[p]++;
                max_power = max(max_power, p);
            }
            vector<long long> dp(max_power + 1, 0);
            dp[1] = count[1];
            if(max_power >= 2) dp[2] = max(dp[1], 2ll * count[2]);
            if(max_power >= 3) dp[3] = max(dp[2], 3ll * count[3]);

            for(int i = 4; i <= max_power; i++){
                dp[i] = max(dp[i - 1], dp[i - 3] + (long long)count[i] * i);
            }
            return dp[max_power];
        }

        // 先排序再统计，不用哈希表，节约内存，但时间复杂度会高一些
        long long maximumTotalDamage2(vector<int>& power) {
            sort(power.begin(), power.end());
            vector<tuple<int, long long>> uniq;
            for(auto &p : power){
                if(uniq.empty() || get<0>(uniq.back()) != p){
                    uniq.emplace_back(p, 1);
                } else {
                    get<1>(uniq.back())++;
                }
            }
            int n = uniq.size();
            vector<long long> dp(n, 0);
            dp[0] = (long long)get<0>(uniq[0]) * get<1>(uniq[0]);
            if(n > 1){
                if(get<0>(uniq[1]) > get<0>(uniq[0]) + 2){
                    dp[1] = dp[0] + (long long)get<0>(uniq[1]) * get<1>(uniq[1]);
                } else {
                    dp[1] = max(dp[0], (long long)get<0>(uniq[1]) * get<1>(uniq[1]));
                }
            }
            for(int i = 2; i < n; i++){
                long long cur = (long long)get<0>(uniq[i]) * get<1>(uniq[i]);
                dp[i] = dp[i - 1];
                if(get<0>(uniq[i]) > get<0>(uniq[i - 1]) + 2){
                    dp[i] = max(dp[i], dp[i - 1] + cur);
                } else {
                    dp[i] = max(dp[i], cur);
                    int j = i - 1;
                    while(j >= 0 && get<0>(uniq[i]) - get<0>(uniq[j]) <= 2) j--;
                    if(j >= 0) dp[i] = max(dp[i], dp[j] + cur);
                }
            }
            return dp[n - 1];
        }
};


int main(){
    vector<int> power = {7,1,6,6};

    Solution s;

    cout << s.maximumTotalDamage2(power) << endl;

}
