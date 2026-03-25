/*


JK 在玩一个横板2D游戏。游戏中有 个源石虫，源石虫有类型 和类型 这两种类型。所有源石虫可以视作在 轴上排成一列，第 个源石虫在坐标 处。

JK 从 处出发，不断向 轴正方向走。每次遇到源石虫，她可以选择是否击杀源石虫，击杀第 个源石虫后可以获得 块金币。

每次击杀类型 的源石虫后，就不能击杀随后的 个源石虫中类型 的源石虫。每次击杀类型 的源石虫后，就不能击杀随后的 个源石虫中类型 的源石虫。

JK 最多能获得多少块金币？
输入格式

第一行，三个整数 。

第二行， 个整数，第 个整数 表示击杀第 个源石虫后可以获得的金币数。
第三行， 个整数，表示第 个源石虫的类型。若为 ，则表示类型 的源石虫，若为 ，则表示类型 的源石虫。
输出格式

一个整数，表示 JK 最多能获得的金币数量。
样例
Input

9 2 3
10 2 2 5 4 1 1 1 9
1 1 1 1 2 2 1 2 2

Output

29


*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, x, y;
int a[MAXN], type[MAXN];
int dp[MAXN][MAXN]; // dp[i][j] = 前 i 只源石虫，最近杀类型1的在位置 i，最近杀类型2的在位置 j
int last1[MAXN], last2[MAXN];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
    }
    
    // dp[i] = 考虑前 i 只源石虫的最大金币
    // 需要记录最近杀类型1和类型2的位置
    vector<int> dp(n + 1, 0);
    vector<int> kill1(n + 1, 0); // 最近杀类型1的位置
    vector<int> kill2(n + 1, 0); // 最近杀类型2的位置
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1]; // 不杀第 i 只
        kill1[i] = kill1[i-1];
        kill2[i] = kill2[i-1];
        
        if (type[i] == 1) {
            // 类型1：检查是否在之前类型2的影响范围内
            if (i - kill2[i-1] > y || kill2[i-1] == 0) {
                // 可以杀
                if (dp[i-1] + a[i] > dp[i]) {
                    dp[i] = dp[i-1] + a[i];
                    kill1[i] = i;
                    kill2[i] = kill2[i-1];
                }
            }
        } else {
            // 类型2：检查是否在之前类型1的影响范围内
            if (i - kill1[i-1] > x || kill1[i-1] == 0) {
                // 可以杀
                if (dp[i-1] + a[i] > dp[i]) {
                    dp[i] = dp[i-1] + a[i];
                    kill1[i] = kill1[i-1];
                    kill2[i] = i;
                }
            }
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}
