/*
现在是基督降临节，在长为N米的街道上有M个街灯。每个灯照亮了左边K米，右边K米。
也就是说，在X米处的灯，能照亮从X-K到X+K（含）。
当然，街道某处可能被多个灯照亮。所有灯位于不同的位置。

问题在于有可能这些灯没法照亮整条街道。你的任务是，确定最少还要加多少灯，使得整条街道都被照亮。

对于样例1，不需要添加额外的灯。

对于样例2，只需一个，比如13。

输入输出格式

输入描述:
多组测试数据输入。
第一行一个整数N（1<=N<=1000）。
第二行一个整数M（1<=M<=N）。
第三行一个整数K（0<=K<=N）。
接下来M行，每行一个数，保证这些数按升序排列。他们的位置都是互异的。

输出描述:
你需要输出所求的数字。

输入输出样例
输入样例#:

5
2
2
1
5

输出样例#:
复制

0


*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    while(cin >> n){  // 多组测试数据，读到EOF结束
        cin >> m >> k;
        vector<int> pos(m);
        for(int i = 0; i < m; i++){
            cin >> pos[i];
        }

        vector<int> ifLighted(n+2, 0);
        // 标记已照亮的区域
        for(int i = 0; i < m; i++){
            int left = max(1, pos[i] - k);
            int right = min(n, pos[i] + k);
            for(int p = left; p <= right; p++){
                ifLighted[p] = 1;
            }
        }

        // 贪心：从左到右找未照亮区间
        int res = 0;
        int i = 1;
        while(i <= n){
            // 跳过已照亮的区域
            while(i <= n && ifLighted[i]) i++;

            if(i > n) break;  // 全部照亮

            // 找到当前未照亮区间的右端点
            int start = i;
            while(i <= n && !ifLighted[i]) i++;
            int end = i - 1;

            // 计算需要多少灯
            int length = end - start + 1;
            // 每个灯能照亮 2*k+1 长度
            res += (length + 2 * k) / (2 * k + 1);
        }

        cout << res << endl;
    }
}