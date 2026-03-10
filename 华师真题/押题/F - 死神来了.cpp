/*

    1 - n 中取 m个数字
    -> 1-n 中最多取多少个数字可以实现 没有一个数字 是另一个数的倍数
    1.首先不能取1， 
    2。如果取了2，则 n/2 个数字不能取; 如果取了3，则 n/3 个数字不能取 
    贪心：
        取 [1,n] 中高一半的数字， 它们之间互相不为倍数关系
         
        
    耗时13min
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6 + 5;

int main(){
    int n, m;
    while(cin >> n >> m){
        bool flag = true;
        

        if(m <= (n + 1) / 2) flag = false;
        else flag = true;


        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}