
/*
给出一个正整数N，将其划分为K个正整数相加的形式，
问有多少种方案数。注意，我们不关心加数的顺序。
例如，当N=3,K=2时，
我们将3=1+2与3=2+1视为同一种方案。
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    function<int(int, int)> dfs = [&](int i, int j){
        if (i < j) return 0;
        if (j == 1) return 1;
        if (i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        // 划分中至少有一个1 + 划分中没有1（每个数都≥2）
        return dfs(i-1, j-1) + dfs(i-j, j);
    };
    cout << dfs(n, k) << endl;
}