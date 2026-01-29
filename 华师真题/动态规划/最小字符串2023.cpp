/*
给定字符串S（全为大写字母），对任意字符，可扩展也可以不扩展，求给定字符串对应的字典序最小字符串
扩展：如A可以扩展为AA，也可以不扩展，为A
例：
输入AC，输出AAC
输入CA，输出CA
输入AAB，输出AAAAB
输入输出格式

输入描述:
如题
输出描述:
如题
输入输出样例
输入样例#:
AAB

输出样例#:
复制

AAAAB

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    vector<bool> expand(n, false);

    // O(n)优化：记录每个位置后面的最小值
    vector<int> minAfter(n);
    minAfter[n-1] = s[n-1];
    for(int i = n-2; i >= 0; i--){
        minAfter[i] = min((int)s[i], minAfter[i+1]);
    }

    // 如果后面有比当前字符小或相等的字符，则扩展
    // 只有当后面所有字符都严格大于当前字符时，才不扩展
    for(int i = 0; i < n; i++){
        if(i == n-1){
            // 最后一个字符，不扩展
            expand[i] = false;
        } else if(minAfter[i+1] < s[i]){
            // 后面有更小的字符，不扩展
            expand[i] = false;
        } else {
            // 后面没有比当前小的字符，扩展
            expand[i] = true;
        }
    }

    for(int i = 0; i < n; i++){
        if(expand[i])
            cout << s[i] << s[i];
        else
            cout << s[i];
    }
    return 0;
}
