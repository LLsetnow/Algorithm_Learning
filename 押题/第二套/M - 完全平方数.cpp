#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10005;


int wanquan[105];
int dp[MAXN];
int main(){
    int n; cin >> n;
    memset(wanquan, 0, sizeof(wanquan));
    memset(dp, 0x3f, sizeof(dp));

    for(int i = 1; i <= 100; i++){
        wanquan[i] = i * i;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        // 找到第一个 大于 i 的完全平方数的索引
        int idx = upper_bound(wanquan + 1, wanquan + 1 + 100, i) - wanquan;
        for(int j = 0; j < idx; j++){
            dp[i] = min(dp[i], dp[i - wanquan[j]] + 1);
        }
    }
    cout << dp[n];

}