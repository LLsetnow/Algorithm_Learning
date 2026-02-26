/*
给定一个int型整数x ,将x 的二进制表示中第i位和第j位的值互换。0 ≤ i , j ≤ 31 

注意: x 的二进制表示的最右边为第0位。
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, i, j;
    cin >> x >> i >> j;

    int bit_i = (x >> i) & 1;
    int bit_j = (x >> j) & 1;
    if(bit_i != bit_j){
        x ^= (1 << i) ^ (1 << j);
    }
    
    cout << x << endl;
    return 0;
}