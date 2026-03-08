#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
/*
flowers[n] 
flowers[i]是第i株花当前已培育的花朵数目
newFlowers（表示小明额外可培育的花朵最大数目），

如果  flowers[i] >= target
    总开心度 = 完善花组的数目 * full + 剩余不完善花组中，花朵数目的最小值 * partial


输入描述:
输入包含一行，按以下顺序给出所有数据：
第一个整数n（1 ≤ n ≤ 1e5），表示花的株数；

接下来n个整数，表示数组flowers（0 ≤ flowers[i] ≤ target）；

随后四个整数，依次表示
newFlowers（0 ≤ newFlowers ≤ 1e14）、
target（1 ≤ target ≤ 1e5）、
full（1 ≤ full ≤ 1e5）、
partial（1 ≤ partial ≤ 1e5）。

输出描述:
输出一个整数，表示能获得的最大总开心度。
输入输出样例
输入样例#:

3 2 4 5 3 7 10 2

输出样例#:

16



*/ 
const i64 MAXNUM = 1e5;
const i64 MAXNEWFLOW = 1e14;
i64 n, newFlowers, target, full, partial;
i64 cntFlow[MAXNUM + 1];    //有i朵花的株数
i64 preCnt[MAXNUM + 1];     //cnt前缀和
i64 lowNeed[MAXNUM + 1];    //将最小值拉到 i 所需的花的数量

int main(){
    cin >> n;
    vector<int> flowers(n);
    memset(cntFlow, 0, sizeof(cntFlow));
    memset(preCnt, 0, sizeof(preCnt));
    memset(lowNeed, 0, sizeof(lowNeed));
    for(auto &x : flowers){
        cin >> x;
        cntFlow[x]++;
    }

    for(int i = 1; i <= MAXNUM; i++){
        preCnt[i] = preCnt[i - 1] + cntFlow[i];
        lowNeed[i] = lowNeed[i - 1] + preCnt[i - 1];
        // cout << lowNeed[i] << " ";
    }
    cin >> newFlowers >> target >> full >> partial;

    // 枚举暴力解
    // newFlowers 分为两部分，一部分用于使不到target的 到达target; 一部分用于填充低
    sort(flowers.begin(), flowers.end());
    i64 tarIdx = 0;
    // 找到第一个 >= target的下标，没有则为n
    while(tarIdx < n && flowers[tarIdx] < target) tarIdx++;
    // 枚举填平低处的花
    i64 maxScore = 0;   // 最大得分
    for(i64 i = flowers[0]; i < target; i++){
        if(lowNeed[i] > newFlowers) break;
        i64 highFlowers = newFlowers - lowNeed[i];  // 填充多的花的数量
        i64 targetCnt = n - tarIdx;     // 完善花组数量
        i64 j = tarIdx - 1;
        // 从不到target的最多的花株开始填充
        while(highFlowers && j >= 0){
            i64 x;  // 需要填充的花的数量
            if(flowers[j] < i){
                x = target - i;
            }
            else{
                x = target - flowers[j];
            }
            if(highFlowers >= x){
                targetCnt++;
                highFlowers -= x;
                j--;
            }
            else    
                break;
        }
        // 计算得分 当前低处为i, targetCnt 为完善花组数量
        i64 score = i * partial + targetCnt * full;
        maxScore = max(maxScore, score);
    }
    cout << maxScore;

}