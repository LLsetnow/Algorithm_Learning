/*
给定n个整数 a1,…,an

问 [l,r] 中有多少数x，满足 ∃i,x%ai=0
输入输出格式
输入描述:
第一行给定测试组数T。

对于每组测试数据，第一行给定三个整数n,l,r，第二行n个整数，表示 a1,…,an 。
输出描述:
T行，每行输出一个整数，表示答案。
输入输出样例
输入样例#:

2
2 5 20
2 3
3 201 1120
3 7 11


输出样例#:
复制

10
443

提示
T≤10,n≤15,2≤ai≤10^6,1≤l≤r≤10^9

对 50% 的数据， r−l≤10^5 ​


*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int INF = 1e9;

int a[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    // 暴力解 通过80%
    while(T--){
        int n, l, r;
        cin >> n >> l >> r;
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = l; i <= r; i++){
            for(int j = 0; j < n; j++){
                if(i % a[j] == 0){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}