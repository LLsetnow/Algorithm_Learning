/*
给定一个长度为 的非负整数序列 ，求一个平均数最大的，长度不小于 的子段。
输入输出格式
输入描述:
第一行用空格分隔的两个整数  和 ；
第二行为  个用空格隔开的非负整数，表示 。
输出描述:
输出一个整数，表示这个平均数的 1000 倍。不用四舍五入，直接输出。
输入输出样例
输入样例#:

10 6
6 4 2 10 3 8 5 9 4 1

输出样例#:
复制

6500

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int a[MAXN];
int s[MAXN];

int main(){

    int n, L;
    cin >> n >> L;
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    double res = -1;
    for(int i = 1; i + L - 1 <= n; i++){
        // 找到以a[i]开头的最大平均数
        // [i - i+L-1] 的和
        int sum = s[i + L - 1] - s[i - 1];
        double ave = (double)sum / (double)L;
        int cnt = L;
        int k = i + L;
        while(k <= n){
            if((double)a[k] > ave){
                cnt++;
                sum += a[k];
                ave = (double)sum / (double)cnt;
                k++;
            }
            //else break;
        }
        res = max(res, ave);
    }
    printf("%d", (int)(res * 1000));
}
