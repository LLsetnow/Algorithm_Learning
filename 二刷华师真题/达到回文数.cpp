#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e4 + 5;
int a[MAXN];


bool huiwen(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int reverse(int x){
    int reversed = 0;
    while(x){
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}

// 耗时10min
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    while(!huiwen(s)){
        // cout << s << endl;
        cnt++;
        int x = stoi(s);
        x += reverse(x);
        s = to_string(x);
    }
    cout << cnt << " " << s; 

}
