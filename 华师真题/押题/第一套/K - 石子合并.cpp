#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int n;
int a[MAXN];          // 每堆石子的质量
int sum[MAXN];        // 前缀和
int dp[MAXN][MAXN];   // dp[i][j]表示合并区间[i,j]的最小代价

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    // 初始化dp数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 边界条件 只有一堆石子，不需要合并
            if (i == j) dp[i][j] = 0;
            // 初始设置为极大数
            else dp[i][j] = INF;
        }
    }

    // 区间dp：枚举区间长度
    for (int len = 2; len <= n; len++) {
        // 枚举区间起点
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            // 枚举分割点k，将[i,j]分成[i,k]和[k+1,j]
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}