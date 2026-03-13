#include <bits/stdc++.h>
using namespace std;


int main(){
    string order;
    string s;
    cin >> order >> s;
    int dic[26];
    // 字典顺序初始化
    for(int i = 0; i < 26; i++){
        dic[i] = i;
    }
    for(int i = 0; i < order.size(); i++){
        // 数字越小 越在前
        dic[order[i] - 'a'] = i;
    }
    sort(s.begin(), s.end(), [&](char &a, char &b){
        return dic[a - 'a'] < dic[b - 'a'];
    });
    cout << s << '\n';
}