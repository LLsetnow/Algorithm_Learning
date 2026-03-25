/*


n个干员，每个干员工资为costi ，贡献值为vali 。

给出 m 次询问，每次询问：当你能承受的总工资为 w 时，能收获最大的贡献值是多少。  
输入格式

第一行，两个整数 n, m。 

接下来n 行，每行两个整数 ，表示每个干员的工资和贡献值。

接下来m行，每行一个数 ，表示单次询问中的可以承受的总工资。
输出格式

输出共行，每行一个数表示你的答案。
样例
Input

4 3
1 2
2 1
1 1
2 3
5
1
0

Output

6
2
0


*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXW = 1005;
int n, m;
int cost[MAXN], val[MAXN];
int dp[MAXN][MAXW];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> val[i];
    }
    
    // 预处理 DP：dp[i][j] = 前 i 个干员，总工资为 j 时的最大贡献值
    // 01背包
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1000; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + val[i]);
            }
        }
    }
    
    // 回答询问
    while (m--) {
        int w;
        cin >> w;
        w = min(w, 1000);
        cout << dp[n][w] << endl;
    }
    
    return 0;
}
