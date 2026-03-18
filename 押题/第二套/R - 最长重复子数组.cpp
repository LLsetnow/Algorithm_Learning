/*

给定两个整数数组 nums1 和 nums2，返回两个数组中公共的、长度最长的连续子数组的长度。

子数组是指数组中连续的一部分。
输入输出格式
输入描述:
第一行输入两个整数 n 和 m（以空格分隔），分别表示数组 nums1 的长度和数组 nums2 的长度；
第二行输入 n 个整数（以空格分隔），表示数组 nums1 的元素；
第三行输入 m 个整数（以空格分隔），表示数组 nums2 的元素；
数据范围：0 ≤ n, m ≤ 1000，数组元素为整数（-100 ≤ 元素值 ≤ 100）。
输出描述:
输出一个非负整数，表示两个数组中最长重复子数组的长度。
输入输出样例
输入样例#:

5 5
1 2 3 2 1
3 2 1 4 7

输出样例#:
3

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int a[MAXN], b[MAXN];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    // dp[i][j] 表示以 a[i] 和 b[j] 结尾的最长重复子数组的长度
    int dp[MAXN][MAXN] = {0};
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;

}
