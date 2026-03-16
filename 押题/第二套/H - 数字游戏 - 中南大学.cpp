/*
这是一个完全背包问题：求凑出目标值m的最少物品数
使用DP优化：dp[j]表示凑出j的最少数字个数
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 1005;
int a[MAXN];
int dp[MAXM];  // dp[j] = 凑出j的最少数字个数

int main(){
    int T, n, m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) cin >> a[i];

        // 初始化：除了dp[0]=0，其他都是INF
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        // 完全背包：每个数字可以用多次
        for(int i = 1; i <= n; i++){
            for(int j = a[i]; j <= m; j++){
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }

        if(dp[m] >= 0x3f) cout << -1 << endl;
        else cout << dp[m] << endl;
    }
    return 0;
}