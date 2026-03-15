/*
一个N×N的网格，你一开始在(1,1)，即左上角。每次只能移动到下方相邻的格子或者右方相邻的格子，问到达(N,N)，即右下角有多少种方法。

但是这个问题太简单了，所以现在有M个格子上有障碍，即不能走到这M个格子上。
输入输出格式
输入描述:
输入文件第1行包含两个非负整数N,M，表示了网格的边长与障碍数。

接下来M行，每行两个不大于N的正整数x,y。表示坐标(x, y)上有障碍不能通过，且有1≤x, y≤n，且x,y至少有一个大于1，并请注意障碍坐标有可能相同。

N≤1000,M≤100000
输出描述:
一个非负整数，为答案 mod100003后的结果。
输入输出样例
输入样例#:

3 1
3 1

输出样例#:
复制

5

耗时:29min
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e3 + 5;
const int M = 1e5 + 5;
const int MOD = 1e5 + 3;
int block[N][N] = {0};  // 1为障碍 0为空


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int r, c;
        cin >> r >> c;
        block[r][c] = 1;
    }

    // dp 时间复杂 O(n * n / 2)
    // dp[i][j] 表示到达[i, j]的方法数 [1-based]
    vector<vector<i64>> dp(n+1, vector<i64>(n+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(block[i][j]) dp[i][j] = 0;
            else if(i == 1 && j == 1) dp[i][j] = 1;  // 起点
            else if(i == 1) dp[i][j] = dp[i][j-1];  // 第一行只能从左边来
            else if(j == 1) dp[i][j] = dp[i-1][j];  // 第一列只能从上边来
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][n]; 
}