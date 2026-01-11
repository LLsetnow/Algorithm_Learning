/*
问题描述

有一个长度为 n 的数组（n 是 10 的倍数），每个数 ai​ 都是区间 [0,9] 中的整数。
小明发现数组里每种数出现的次数不太平均，而更改第 i 个数的代价为 bi​，
他想更改若干个数的值使得这 10 种数出现的次数相等（都等于 n/10​），
请问代价和最少为多少。

输入格式

输入的第一行包含一个正整数 n。

接下来 n 行，第 i 行包含两个整数 ai,bi​ ，用一个空格分隔。
输出格式

输出一行包含一个正整数表示答案。
样例输入

10
1 1
1 2
1 3
2 4
2 5
2 6
3 7
3 8
3 9
4 10


样例输出

27

样例说明

只更改第 1,2,4,5,7,81,2,4,5,7,8 个数，需要花费代价 1+2+4+5+7+8=271+2+4+5+7+8=27。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> count(10, 0);
    vector<vector<int>> cost(10);  // cost[digit]存储所有该数字的修改代价

    for(int i = 0; i < n; i++){
        int key, value;
        cin >> key >> value;
        cost[key].push_back(value);
        count[key]++;
    }

    // 对每个数字的修改代价从小到大排序
    for(int i = 0; i < 10; i++){
        sort(cost[i].begin(), cost[i].end());
    }

    int target = n / 10;  
    long long ans = 0;


    for(int i = 0; i < 10; i++){
        if(count[i] > target){
            int need_modify = count[i] - target;
            // 取前need_modify个最小的代价
            for(int j = 0; j < need_modify; j++){
                ans += cost[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}