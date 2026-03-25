/*
给定一个集合，其中包含若干个区间。每个区间由一对整数对 表示，其中 表示区间的开始， 表示区间的结束，并且 。
你的任务是移除最少数量的区间，使得剩余的区间之间没有重叠。
输入输出格式
输入描述:
第一行一个整数 ，表示区间的数量。
接下来  行，每行两个整数  和 ，表示一个区间的开始和结束。

输出描述:
输出一个整数，表示为了使剩余的区间没有重叠，需要移除的最少区间数。
输入输出样例
输入样例#:

4
1 3
2 4
3 5
6 8

输出样例#:
复制

1



*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n;
pair<int, int> a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    });
    int ans = 0;

    int last = a[1].second;
    for (int i = 2; i <= n; i++) {
        if(a[i].first < last){
            ans++;
        }else{
            last = a[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}