/*
思路：
    找到所有全1字串, 记录起点和终点, 再计算符合条件的数量

耗时：14min
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = 0, r = 0;
    vector<pair<int, int>> childStrs;    //全1字串, 记录起点和终点
    while(l < n && r < n){
        if(s[r] == '0'){
            if(l != r){
                pair<int, int> x;
                x.first = l;
                x.second = r - 1;
                childStrs.push_back(x);
            }
            r++;
            l = r;
        }
        else{
            r++;
        }
    }
    // 最后一个字串
    if(s[n - 1] != '0'){
        pair<int, int> x;
        x.first = l;
        x.second = r - 1;
        childStrs.push_back(x);
    }
    int res = 0;
    // 长度刚好的+1， 其他：length - m + 1
    for(auto &x : childStrs){
        int legth = x.second - x.first + 1;
        if(legth >= m){
            int a = m;
            while(legth - a + 1){
                res += legth - a + 1;
                a++;
            }
        }
    }
    cout << res;
}
