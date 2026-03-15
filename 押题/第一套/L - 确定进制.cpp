#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 1e6;


i64 Calculate(string s, int jinzhi){
    // X进制 转十进制
    i64 res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res * jinzhi + (s[i] - '0');
    }
    return res;
}
int main(){
    int p, q, t;
    cin >> p >> q >> t;

    int x = 0;
    string sp = to_string(p);
    string sq = to_string(q);
    string st = to_string(t);
    for(int i = 0; i < sp.size(); i++) x = max(x, sp[i] - '0');
    for(int i = 0; i < sq.size(); i++) x = max(x, sq[i] - '0');
    for(int i = 0; i < st.size(); i++) x = max(x, st[i] - '0');

    int res = 0;    // 没有正确的解 输出0
    for(int i = x + 1; i < 1e9; i++){
        i64 dp = Calculate(sp, i);
        i64 dq = Calculate(sq, i);
        i64 dr = Calculate(st, i);
        if(dp * dq == dr){
            res = i;
            break;
        }
    }
    cout << res;
}