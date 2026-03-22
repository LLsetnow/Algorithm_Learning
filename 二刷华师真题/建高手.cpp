#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int a[MAXN];
bool Judge(ll mid, int n, int k){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += mid / a[i];
    }
    if(cnt >= k) return true;
    else return false;
}
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    // 二分查找答案t
    // 最小 0 最大1e18
    ll l = 1, r = 1e18;
    ll res;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        // 计算产量
        if(Judge(mid, n, k)){
            res = mid;  // 等号出现在这
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << res;
}