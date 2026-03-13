// 耗时27min
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e4 + 5;
int cnt2[N];    // cnt2[i] 表示i中质因子2的个数
int prefix[N];  // prefix[i] 表示1*2*...*i中质因子2的总数，即i!中2的因子个数

int main(){
    // 预处理每个数中质因子2的个数
    for(int i = 1; i < N; i++){
        int x = i, cnt = 0;
        while(x % 2 == 0){
            cnt++;
            x /= 2;
        }
        cnt2[i] = cnt;
        prefix[i] = prefix[i-1] + cnt;
    }

    i64 n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        // n!/(n-m)!中2的因子个数 = prefix[n] - prefix[n-m]
        int ans = prefix[n] - prefix[n - m];
        cout << ans << endl;
    }
}