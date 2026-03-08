/*
给出一个长度为 n 的由正整数构成的序列，你需要从中删除一个正整数，很显然你有很多种删除方式，你需要对删除这个正整数以后的序列求其最长上升子串，请问在所有删除方案中，最长的上升子串长度是多少。

这里给出最长上升子串的定义：即对于序列中连续的若干个正整数，满足 ，则称这连续的若干个整数构成的子串为上升子串，在所有的上升子串中，长度最长的称为最长上升子串。
输入输出格式
输入描述:
输入第一行仅包含一个正整数 n，表示给出的序列的长度。
接下来一行有 n 个正整数，即这个序列，中间用空格隔开。
，
输出描述:
输出仅包含一个正整数，即删除一个数字之后的最长上升子串长度。
输入输出样例
输入样例#:

5
2 1 3 2 5

输出样例#:
3

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dpl[N];     // dpl[i]: 从左边开始，以i结尾的最长上升子串长度（1-based）
int dpr[N];     // dpr[i]: 从右边开始，以i开头的最长上升子串长度（1-based）
int a[N];       // 原始数组（1-based）

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 特判
    if(n == 1) {cout << 0; return 0;}

    // 初始化
    memset(dpl, 0, sizeof(dpl));
    memset(dpr, 0, sizeof(dpr));

    // 从左到右计算dpl
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dpl[i] = 1;
        } else if(a[i] > a[i-1]){
            dpl[i] = dpl[i-1] + 1;  // 上升，延续
        } else {
            dpl[i] = 1;  // 重新开始
        }
    }

    // 从右到左计算dpr
    for(int i = n; i >= 1; i--){
        if(i == n){
            dpr[i] = 1;
        } else if(a[i] < a[i+1]){
            dpr[i] = dpr[i+1] + 1;  // 上升（反向），延续
        } else {
            dpr[i] = 1;  // 重新开始
        }
    }

    int ans = 0;

    // 删除第1个元素，剩余从第2个开始
    if(n >= 2) ans = max(ans, dpr[2]);

    // 删除第n个元素，剩余到第n-1个结束
    if(n >= 2) ans = max(ans, dpl[n-1]);

    // 枚举删除中间位置
    for(int i = 2; i <= n-1; i++){
        if(a[i+1] > a[i-1]){
            // 删除i后，a[i-1]和a[i+1]可以连接
            ans = max(ans, dpl[i-1] + dpr[i+1]);
        } else {
            // 删除i后，a[i-1]和a[i+1]不能连接，取较大的一边
            ans = max(ans, max(dpl[i-1], dpr[i+1]));
        }
    }

    cout << ans;
    return 0;
}