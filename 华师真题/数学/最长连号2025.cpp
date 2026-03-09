/*
给定一个长度为的数组，输出里面公差为1的最长连续上升子段的长度。

输入输出格式
输入描述:
输入为单样例。
第一行包含一个整数（不会太大导致超时）。
第二行包含个整数。

输出描述:
输出一行结果，表示最长连续上升子段*的长度。

输入输出样例
输入样例#:

5
1 2 1 2 3

输出样例#:
复制

3

提示
解释
前面的1 2长度为2，后面的1 2 3长度为3，则输出3


耗时：8min
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];   //[1-based]

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 1, r = 2;
    int legth = 1;
    int res = 0;
    while(l <= n && r <= n){
        if((a[r] - a[r - 1]) == 1) legth++;
        else{
            l = r;
            res = max(res, legth);
            legth = 1;
        }
        r++;
    }
    res = max(res, legth);

    cout << res;
}