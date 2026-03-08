#include <bits/stdc++.h>
using namespace std;
/*
给定字符串S（全为大写字母），对任意字符，可扩展也可以不扩展，求给定字符串对应的字典序最小字符串
扩展：如A可以扩展为AA，也可以不扩展，为A
例：
输入AC，输出AAC
输入CA，输出CA
输入AAB，输出AAAAB
输入BCAA，输出BCCAAA

思路：
    DP: dp[i] 表示从位置i开始的最小后缀字符串（可以选择扩展或不扩展s[i]）
    对于每个位置i，比较：
    1. 不扩展s[i]: 输出s[i]，后面接dp[i+1]
    2. 扩展s[i]: 输出s[i]+s[i]，后面接dp[i+1]
    取字典序较小的
*/

int main(){
    string s;
    cin >> s;

    int n = s.size();

    // dp[i]: 从位置i开始的最小后缀字符串
    vector<string> dp(n + 1);
    dp[n] = "";  // 空串

    // expand[i]: 从位置i开始，扩展s[i]后能得到的最小后缀字符串
    vector<string> expand_dp(n + 1);
    expand_dp[n] = "";

    // 从后往前计算
    for(int i = n - 1; i >= 0; i--){
        // 不扩展s[i]: s[i] + dp[i+1]
        string noExpand = string(1, s[i]) + dp[i + 1];

        // 扩展s[i]: s[i] + s[i] + dp[i+1]
        string expand = string(1, s[i]) + string(1, s[i]) + dp[i + 1];

        // dp[i] 是两者中较小的
        if(noExpand < expand){
            dp[i] = noExpand;
            expand_dp[i] = expand;  // 强制扩展的情况
        } else {
            dp[i] = expand;
            expand_dp[i] = noExpand;  // 但如果强制扩展，就是noExpand
        }
    }

    cout << dp[0];
    return 0;
}