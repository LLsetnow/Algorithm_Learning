/*
 Time Limit: 1000 ms
Memory Limit: 256 mb

就是输入一个数字n，然后输入n个字符串

每个字符串包含13个字符，有2，3，4，5，6，7，8，9，10，J，Q，K，A

其中J算1分，Q算2分，K算3分，A算4分

输出这些字符加在一起的最终分数
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(auto& c : s){
            if(c == 'J') ans+=1;
            else if(c == 'Q') ans+=2;
            else if(c == 'K') ans+=3;
            else if(c == 'A') ans+=4;
        }
    }
    cout << ans << endl;
}

