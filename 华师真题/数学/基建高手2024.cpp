#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int MAXN = 1e5 + 5;
int a[MAXN];    //[1-based]

i64 CalK(i64 time, int n){
    i64 sum = 0;
    for(int i = 1; i <= n; i++){
        sum += time / a[i];
    }
    return sum;
}
int main(){
    int n, k;
    cin >> n >> k;
    int max_a = 0;
    int min_a = INT32_MAX;
    for(int i = 1; i <=n; i++) cin >> a[i]; 
    
    // 二分查找时间time 判断是否产出k块黄金
    i64 l = 0, r = 1e18;
    while(l < r){
        i64 mid = l + (r - l) / 2;
        if(CalK(mid, n) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l;
}