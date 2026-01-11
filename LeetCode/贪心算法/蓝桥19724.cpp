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

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a2, a3, a4, b4, b6;
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        /*
            桌子人数组合方式
            第一个数：容纳2人寝个数
            第二个数：容纳3人寝个数
            第三个数：容纳4人寝个数
            第四个数：该桌子容纳总人数

        */
        vector<tuple<int, int, int, int>> patterns = {
            {0, 2, 0, 6},
            {1, 0, 1, 6},
            {3, 0, 0, 6},
            {1, 1, 1, 5},
            {0, 0, 1, 4},
            {2, 0, 0, 4},
            {0, 1, 0, 3},
            {1, 0, 0, 2},
        };
        // 创建桌子，优先安排六人桌

        vector<int> tables(b6, 6);
        tables.insert(tables.end(), b4, 4);
        int ans = 0;
        // 安排每张桌子的 人数组合
        for(auto &t : tables){
            for(auto &[c2, c3, c4, sum] : patterns){
                if(a2 >= c2 && a3 >= c3 && a4 >= c4 && t >= sum){
                    // 安排这组人到当前桌子
                    a2 -= c2;
                    a3 -= c3;
                    a4 -= c4;
                    ans += sum;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}