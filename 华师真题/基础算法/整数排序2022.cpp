/*
输入若干个int类型整数，将整数按照位数由大到小排序，
如果位数相同，则按照整数本身从小到大排序。例如,

输入:10 -3 1 23 89 100 9 -123

输出:-123 100 10 23 89 -3 1 9

输入的整数个数最多不超过10^6个。
输入输出格式

输入描述:
在一行中输入若干个整数，整数之间用一个空格分隔。
输出描述:
在一行中输出排序好的整数，整数之间用一个空格分隔。


输入输出样例
输入样例#:
10 -3 1 23 89 100 9 -123

输出样例#:
-123 100 10 23 89 -3 1 9
*/

#include <bits/stdc++.h>
using namespace std;
int weishu(int x);

int main(){
    vector<pair<int, int>> vec;
    pair<int, int> p;
    while(cin >> p.first) vec.push_back(p); 
    for(auto &x : vec){
        x.second = weishu(x.first);
    }
    // 先按照 位数 降序，再按照 数字大小 升序
    // 大降 小升
    sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for(auto x : vec){
        cout << x.first << " ";
    }
}

int weishu(int x){
    int res = 0;
    if(x < 0) x = abs(x);
    if(x == 0) return 1;
    while(x){
        res++;
        x /= 10;
    }
    return res;
}