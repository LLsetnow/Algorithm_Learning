/*
在一个神秘的古老遗迹中，有许多隐秘的通道。
这些通道在地面上形成了许多条直线，并且没有三条直线相交于同一点。
作为一名探险家，你的任务是计算这些通道之间的所有可能交点的数量。

给定遗迹中的N条直线，这些直线中没有三条直线相交于同一点。你的任务是计算这些直线之间可能形成的不同交点数的种类。
输入输出格式
输入描述:
输入包含一行，一个整数N，表示有N条直线。1 ≤ N ≤ 25
输出描述:
输出一个整数，表示这些直线可以形成多少种不同的交点数目。
输入输出样例
输入样例#:

4

输出样例#:
复制

5

提示
样例解释：
4条直线可能形成的交点数是0,3,4,5,6，共5种


将互相平行的直线归为一组{}
给直线编号[0-based]

0交点: {0,1,2,3}                                
3交点：{0,1,2}, {3} 3 * 1 = 3;
4交点：{0,1}, {2,3} 2 * 2 = 4;
5交点：{0,1}, {2}, {3} 1 * 2 + 1 * 2 + 1 * 1 = 5;
6交点：{0}, {1}, {2}, {3} 3 + 2 + 1 = 6;

回溯 找到数字n的所有分解方法：
4 = 1 + 1 + 1 + 1； -> 6交点
4 = 1 + 1 + 2;      -> 5交点
4 = 1 + 3;          -> 3交点
4 = 2 + 2;          -> 4交点
4 = 4;              -> 0交点

两个for循环 res += a[i] * a[j];
res为交点数, 用buck[res] = 1 来去除重复的交点数量
最后总计buck[]中1的数量，即为交点数的可能情况数量


*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e4 + 5;
int buck[MAXN];

int main(){
    int n;
    cin >> n;
    memset(buck, 0, sizeof(buck));
    vector<vector<int>> paths;
    vector<int> path;
    function<void(int, int)> backtrack = [&](int sum, int start){
        // 成功回溯
        if(sum == n){
            paths.push_back(path);
            return;
        }
        for(int i = start; sum + i <= n; i++){
            path.push_back(i);
            backtrack(sum + i, i);
            path.pop_back();
        }
    };
    backtrack(0, 1);
    for(auto &path : paths){
        // cout << "path : ";
        // for(int i = 0; i < path.size(); i++) cout << path[i] << " ";
        // cout << endl;
        int cnt = 0;
        for(int i = 0; i < path.size() - 1; i++){
            for(int j = i + 1; j < path.size(); j++){
                cnt+= path[i] * path[j];
            }
        }
        // cout << cnt << endl;
        buck[cnt] = 1;
    }
    int res = 0;
    for(int i = 0; i < MAXN; i++){
        if(buck[i]) res++; 
    }
    cout << res;
}