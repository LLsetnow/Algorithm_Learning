#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        // dp[i] = 得到乘积为i的最小元素个数
        vector<int> dp(n + 1, 1e9);
        // 初始化：a中每个数可以用1个元素得到
        for(auto x : a){
            if(x <= n) dp[x] = 1;
        }
        
        // 排序a，从小到大更新dp
        sort(a.begin(), a.end());
        // 动态规划：对于每个i，考虑用a中的数乘以某个数j得到i
        for(int i = 1; i <= n; i++){
            if(dp[i] == 1e9) continue;  // i无法得到
            for(auto x : a){
                if(i * x > n) break;  // 超过n，后面更大的x也超过n
                dp[i * x] = min(dp[i * x], dp[i] + 1);
            }
        }
        // 输出结果
        for(int i = 1; i <= n; i++){
            cout << (dp[i] == 1e9 ? -1 : dp[i]) << " \n"[i == n];
        }
    }
}