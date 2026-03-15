/*
给定只含01的字符串，找出最长平衡子串的长度（平衡串：包含0和1的个数相同）
输入输出格式
输入描述:
多组测试数据输入。
输入一串01字符串，字符串长度最大为100000。
输出描述:
请输出最长的平衡子串的长度。
输入输出样例
输入样例#:

101011000

输出样例#:
复制

8


*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int n = s.size();
    
        // 用来存储每一种前缀和出现的起点
        // 只要找到有 相同前缀和的最大区间
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;  // 当前前缀和（0看作-1，1看作+1）
        int res = 0;
    
        for(int i = 0; i < n; i++){
            
            if(s[i] == '1') sum++;
            else sum--;
            // 之前出现过 该前缀和
            if(mp.find(sum) != mp.end()){
                res = max(res, i - mp[sum]);
            }
            // 第一次出现的前缀和
            else{
                mp[sum] = i;
            }
        }
        cout << res << endl;
    }
    return 0;
}