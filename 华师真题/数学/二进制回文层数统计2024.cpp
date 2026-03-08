#include <bits/stdc++.h>
using namespace std;

bool ifHuiWen(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l++] != s[r--]) return false;
    }
    return true;
    
}

int main(){

    int n;
    cin >> n;

    string binary = bitset<32>(n).to_string();
    // 去掉前导0
    binary = binary.substr(binary.find('1'));

    int res = 0;
    while(ifHuiWen(binary) && binary.size() > 1){
        res++;
        binary = binary.substr(0, binary.size() / 2);
    }
    cout << res;
}