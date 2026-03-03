/*

给定长度为n的字符串S,定义其子字符串为S中连续的字符所组成的字符串。
若个字符串的每一个字符都独一 无二，那么我们称这样的字符串是美丽的，
例如abc是美丽的，但是abb不是美丽的。
请输出S的最长美丽子串的长度。

数据规定

    30% ：S长度 [1,100]
    60% ：S长度 [1,10000]
    100% ：S长度 [1,100000]

输入输出格式
输入描述:
一行一个字符串S

输出描述:
一行一个整数，表示答案。

输入输出样例

输入样例#:
abcddbcd

输出样例#:
4

提示
样例中最长美丽字串为abcd，长度为4

思路:
    双指针, 构建一个 ifExised[]
    a '97' z '122'
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    int res = 0;
    if(s.size() < 2){
        cout << s.size() << endl;
        return 0;
    }

    vector<int> ifExised(130, 0);
    int i = 0;
    int j = 0;
    int legth = 0;
    int n = s.size();
    while(i < n && j < n){
        // 新字符
        if(!ifExised[s[j]]){
            ifExised[s[j]] = 1;
            j++;
            legth++;
            if(legth > res) 
            res = legth;
            // cout << "new letter" << endl;
            // cout << "legth = " << legth << " i = " << i << " j = " << j << endl;
        }
        // 字符重复 左指针右移 直到不重复
        else{
            while(s[i] != s[j]){
                ifExised[s[i]] = 0;     // 删除s[i]
                i++;
                legth--;
            }
            i++;
            j++;

            // cout << "chongfu" << endl;
            // cout << "legth = " << legth << " i = " << i << " j = " << j << endl;
        }

    }
    cout << res << endl;
    return 0;
}