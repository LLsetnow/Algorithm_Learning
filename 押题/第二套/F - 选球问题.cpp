#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int ball[30]; // [1-26]
int main(){

    int n, k;
    while(cin >> n >> k){
        memset(ball, 0, sizeof(ball));
        for(int i = 1; i <= n; i++){
            char x;
            cin >> x;
            ball[x - 'a' + 1]++;
        }


        int res = 0;
        int pre = -10;
        int cnt = 0;

        for(int i = 1; i <= 26; i++){
            if(cnt == k) break;
            if(ball[i] && i - pre >= 2){
                // cout << "add" << i << endl;
                pre = i;
                res += i;
                cnt++;
            }
        }
        if(cnt < k) cout << "-1" << endl;
        else cout << res << endl;
    }
}