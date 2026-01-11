/*
小蓝在无聊时随机生成了一个长度为 nn 的整数数组，
数组中的第 i 个数为 ai​，他觉得随机生成的数组不太美观，
想把它变成回文数组.
小蓝一次操作可以指定相邻的两个数，将它们一起加 1 或减 1；
也可以只指定一个数加 11 或减 11，请问他最少需要操作多少次能把这个数组变成回文数组？

输入格式
输入的第一行包含一个正整数 nn 。
第二行包含 nn 个整数 a1,a2,⋯ ,ana1​,a2​,⋯,an​，相邻整数之间使用一个空格分隔。

输出格式

输出一行包含一个整数表示答案。
样例输入

4
1 2 3 4
[copy]

样例输出

3

*/

#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    vector<int> diff(n/2);
    for(int i = 0; i < n/2; i++){
        diff[i] = a[i] - a[n - 1 - i];
    }
    long long ans = 0;
    n /= 2;
    for(int i = 0; i < n; i++){
        if(i != n - 1){
            // 如果相邻两个同正
            if(diff[i] > 0 && diff[i+1] > 0){
                int min_abs = min(diff[i], diff[i+1]);
                ans += min_abs;
                diff[i] -= min_abs;
                diff[i+1] -= min_abs;
            }
            // 如果相邻两个同负
            else if(diff[i] < 0 && diff[i+1] < 0){
                int min_abs = min(-diff[i], -diff[i+1]);
                ans += min_abs;
                diff[i] += min_abs;
                diff[i+1] += min_abs;
            }
        }
        // 最后一个数
        ans += abs(diff[i]);
    }
    cout << ans << endl;
}