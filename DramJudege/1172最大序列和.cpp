#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6;
const ll INF = 1e18; 

int main(){
    int n;
    while(cin >> n){
        ll minS = 0;    // 初始值为0 表示左区间为1时
        ll sum = 0;
        ll res = -INF;
        for(int i = 1; i <= n; i++){
            ll x; 
            cin >> x;
            sum += x;
            // 最大字段和 = 最大右区间 前缀和 - 最小左区间 前缀和 
            // 防止区间大小为0 先计算区间和最大值，再更新最小前缀和
            res = max(res, sum - minS);
            minS = min(minS, sum);
        }
        cout << res << endl;
    }
}