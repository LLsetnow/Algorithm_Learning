#include <bits/stdc++.h>
using namespace std;
int a[32];

bool huiwen(string &s, int n)
{
    // n为检测字符串长度
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]){
            return false;
        }
    }
    return true;
}

// 时间复杂度 O(logn)
int huiwen_n(string &s){
    int n = 32;
    int res = 0;
    while(huiwen(s, n)){
        res++;
        // int x = s.size() / 2;
        // 创建新字符串 费时
        // s = s.substr(0, x);
        n /= 2;
    }
    return res;
}

// 18min 66% 超时
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        unsigned int x; cin >> x;
        // 库函数速度慢
        string s = bitset<32>(x).to_string();

        // for(int i = 0; i < 32; i++){
        //     a[i] = (x & 1);
        //     x >> 1;
        // }

        // cout << s << endl;
        printf("%d\n", huiwen_n(s));
    }
}