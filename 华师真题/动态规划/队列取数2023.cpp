/*
定N个长度为M的整数队列，并且要取K次数，每次取数时可以从任意非空队列的头部取一个数，
并且取数后该队列头部的下一个元素会成为新的头部（如果存在的话）。
请求出这K次取数后能得到的所有数的和最大为多少。
输入输出格式
输入描述:
第一行有三个整数。
接下来的行，每行包含个整数，依次表示一个队列中所有元素。其中最左侧的元素为队头元素。
保证队列中的元素为整数且在中。
输出描述:
只有一行，表示取个数的最大和。
输入输出样例
输入样例#:

2 2 2
5 100
10 3

输出样例#:
复制

105

提示
对于30%的数据，保证n,m<30。

*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    // 输入
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> q(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> q[i][j];
            // 计算价值前缀和
            // 下标 为物体的体积
            if(j > 0) q[i][j] += q[i][j-1];
        }
    }
    // 递归+记忆化
    vector<vector<int>> dp(n + 1, vector<int>(k+1, -1));    // 注意dp初始值为-1
    // c++ 17 function<int(int, int)> dfs = [&](int i, int j){
    // c++ 23
    auto dfs = [&](this auto&& dfs, int i, int j){
        // 递归边界
        if(i < 0) return 0;
        int &res = dp[i][j];    // 注意这边是引用
        // 当前情况以及计算过了
        if(res != -1) return res;
        // res初始值 为不选择i号队列的物品，继承前i-1个队列选择下的价值
        res = dfs(i - 1, j);
        // 开始从第i堆中 选择符合体积j的最大价值物体
        // x+1 为体积 q[i][x] 为这件物品的价值
        for(int x = 0; x < min(m, j); x++){
            res = max(res, dfs(i - 1, j - (x + 1)) + q[i][x]);
        }
        return res;
    };
    cout << dfs(n - 1, k) << endl;
}
