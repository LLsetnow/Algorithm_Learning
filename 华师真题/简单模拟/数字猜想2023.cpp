/*
输入一个正整数x，如果为奇数：先乘3再加1。如果为偶数：除2。直到x变为1，计算操作了多少次
输入输出格式
输入描述:
如题
输出描述:
如题
输入输出样例
输入样例#:

10

输出样例#:
复制

6

提示
10-5-16-8-4-2-1

*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n > 1){
        count++;
        if(n % 2)
            n = n * 3 + 1;
        else    
            n /= 2;
    }
    cout << count;
}