#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;  // 被除数范围
const int NA = 1e6 + 5; // 除数范围
const int MAX_n = 15 * 10 + 5; // 
int a[20];  // [1-based]
vector<array<int, N>> preCnt;
array<int, N> cnt = {0};
int reflect[NA];    // 映射关系 [0-base] 
int ifCal[NA];      // 是否算过
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, l, r;
    cin >> T;
    memset(reflect, 0, sizeof(reflect));
    memset(ifCal, 0, sizeof(ifCal));

    while(T--){
        cin >> n >> l >> r;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int res = 0;
        // 暴力解 O((r - l) * n * T)
        // for(int i = l; i <= r; i++){
        //     int flag = 0;
        //     for(int j = 1; j <= n; j++){
        //         if(i % a[j] == 0) flag = 1;
        //     }
        //     if(flag) res++; 
        // }
        
        // 前缀和优化
        for(int i = 1; i <= n; i++){
            // a[i] 除数
            // 已经算过了
            if(ifCal[a[i]]){
                // reflect[a[i]] 表示前缀和在preCnt中的位置
                int idx = reflect[a[i]];
                res += preCnt[idx][r] - preCnt[idx][l - 1]; 
            }
            // 没算过这个除数
            else{
                cnt.fill(0);
                ifCal[a[i]] = 1;
                int idx = preCnt.size();
                reflect[a[i]] = idx;

                for(int j = a[i]; j <= 1e9; j++){
                    if(j % i == 0)
                    cnt[j] = cnt[j - 1] + 1;
                    else    
                    cnt[j] = cnt[j - 1];
                }
                preCnt.push_back(cnt);
                res += preCnt[idx][r] - preCnt[idx][l - 1]; 
            }
        }

        cout << res << endl;
    }
}