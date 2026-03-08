#include <bits/stdc++.h>
using namespace std;

int a[20];  // [1-based]

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

        int res = 0;
        // 暴力解 O((r - l) * n * T)
        for(int i = l; i <= r; i++){
            int flag = 0;
            for(int j = 1; j <= n; j++){
                if(i % a[j] == 0) flag = 1;
            }
            if(flag) res++; 
        }
        
        cout << res << endl;
    }
}