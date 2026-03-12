// 5min解决
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[26];
int main(){
    string s;
    cin >> s;

    memset(cnt, 0, sizeof(cnt));
    for(auto &c : s){
        cnt[c - 'a']++;
    }

    int res = 0;
    for(int i = 0; i <26; i++){
        res += cnt[i] / 2;
    }

    cout << (res > 9 ? 9 : res);

}