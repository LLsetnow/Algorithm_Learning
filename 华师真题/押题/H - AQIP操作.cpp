#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    string s;
    int m;
    cin >> s;
    cin >> m;
    while(m--){
        char ins;
        cin >> ins;
        if(ins == 'A'){
            // 后增
            char c;
            cin >> c;
            s += c;
        }
        else if(ins == 'I'){
            //插入
            int a;
            string c;
            cin >> a >> c;
            s.insert(a - 1, c);
        }
        else if(ins == 'Q'){
            // 查询字符b频次
            char c;
            cin >> c;
            int cnt = 0;    
            for(int i = 0; i < s.size(); i++) 
                cnt += (s[i] == c);
            cout << cnt << endl;
        }
        else if(ins == 'P'){
            // 输出字符串
            cout << s << endl;
        }
    }

}