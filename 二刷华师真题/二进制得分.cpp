#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;


int fenge(string s){
    if(s == "0") return 0;
    if(s == "1") return 1;
    if(s == "10") return 2;
    if(s == "11") return 3;
    

}

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        if(x <= 1) printf("%d\n", x);
        int res = x;
        string s = bitset<32>(x).to_string();
        int cnt = 0;
        vector<int> idx;
        for(int i = 0; i < 32; i++){
            if(s[i] == '1'){
                cnt++;
                idx.push_back(i);
            } 
        }
        // ①最高位到正中间左边的1 ②正中间两个1夹住的0或者空 ③正中间右边的1到最低位
        if(cnt % 2 == 0){

        }
        // ①最高位到正中间的1的前一个位置 ②正中间的1 ③正中间的1的后一个位置到最低位
        else{
            // 最高位是 idx[0] 中间的1 是idx[cnt / 2] 
        }
    }
}