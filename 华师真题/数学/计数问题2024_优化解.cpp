#include <bits/stdc++.h>
using namespace std;

int a[20];  // [1-based]
long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, l, r;
    cin >> T;

    while(T--){
        cin >> n >> l >> r;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        long long res = 0;
        // 容斥原理：枚举所有非空子集
        for(int mask = 1; mask < (1 << n); mask++){
            long long L = 1;
            int cnt = 0;  // 子集中元素的个数
            bool overflow = false;

            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    cnt++;
                    L = lcm(L, a[i+1]);
                    // 如果lcm超过r，count=0
                    if(L > r){
                        overflow = true;
                        break;
                    }
                }
            }

            if(!overflow){
                long long count = r / L - (l - 1) / L;
                if(cnt % 2 == 1) res += count;  // 奇数个子集相加
                else res -= count;              // 偶数个子集相减
            }
        }

        cout << res << endl;
    }
}