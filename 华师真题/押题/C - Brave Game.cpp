// 10min
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    int c;
    cin >> c;
    while(c--){
        int n, m;
        cin >> n >> m;
        // n 刚好是 m+1 的倍数 则后手win，否则先手win
        if(n % (m + 1)) cout << "first" << endl;
        else cout << "second" << endl;
    }
}