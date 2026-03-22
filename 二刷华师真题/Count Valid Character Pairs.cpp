#include <bits/stdc++.h>
using namespace std;

int a[26];
int main(){
    string s;
    cin >> s;
    for(auto &c : s){
        a[c - 'a']++;
    }

    int res = 0;
    for(int i = 0; i < 26; i++){
        res += a[i] / 2;
    }
    cout << (res > 9 ? 9 : res);
}