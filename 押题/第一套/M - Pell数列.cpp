#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int MAXN = 1e6 + 5;
const int MOD = 32767;
i64 dp[MAXN];
int main(){
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < MAXN; i++) dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
    while(n--){
        i64 res;
        int a;
        cin >> a;
        res = dp[a];
        cout << res << endl;
    }
}