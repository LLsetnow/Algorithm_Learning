#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 105;

ll dp[MAXN];   // [1 - based]
int main(){
    int n;
    memset(dp, 0, sizeof(dp));
    /*
        n = 4
        = 1 + 1 + 1 + 1; 
          1 + 1 + 2; 
          1 + 2 + 1; 
          2 + 1 + 1; 
          2 + 2
        从0出发
    */
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < MAXN; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while(cin >> n){
        cout << dp[n] << endl;
    }
}