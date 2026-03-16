#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 5005;
const int INF = 1e9;
// 耗时5min
int main(){
    int n; cin >> n;
    int res = 0;
    while(n--){
        string s; cin >> s;
        for(auto &c : s){
            if(c == 'J') res += 1;
            if(c == 'Q') res += 2;
            if(c == 'K') res += 3;
            if(c == 'A') res += 4;
        }
    }
    cout << res;
}