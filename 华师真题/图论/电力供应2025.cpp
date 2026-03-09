/*
给定n个村子，
m条连接两个村子的道路。
现在需要给这个村子通电，每个村子可以自己建设一个电站，
也可以向其他村子拉电线，只要连通图中存在至少一个电站，则连接的所有村子都有电。

电线每公里需要c元，问所有村子都通上电的最小的代价。

输入描述:
第一行为—— 村子数n， 道路数m，电线每公里单价c
第二行为n个数——在每个村子建设电站的价格price[]
剩下m行，每行u,v,w 村子距离村子距离为公里
输出描述:
所有村子都通上电的最小的价格
输入输出样例
输入样例:

3 3 1
5 3 4
1 2 1
2 3 1
1 3 3

输出样例:

5

思路： 增加虚拟节点0，从0到每个村子i连边，权值为建站价格price[i]；
原图中每条边(u,v,w)的权值设为c*w。
然后对整个n+1个节点的图求最小生成树，所得MST权值和即为答案。
这等价于每个村子要么自己建站（通过选虚拟节点的边），要么通过电线连接（选原图中的边），且保证全图连通。

Prim(普里姆)算法
*/

#include <bits/stdc++.h>
using namespace std;
const int NODE = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int graph[NODE][NODE];  // graph[0][i]存储虚拟节点0到节点i的边权（建站价格）

// Prim算法生成最小生成树
// 返回最小生成树的总权值
int prim(int n) {
    bool visited[NODE] = {false};
    int lowcost[NODE];
    int total = 0;

    // 从虚拟节点0开始
    for(int i = 0; i <= n; i++) {
        lowcost[i] = graph[0][i];
    }
    visited[0] = true;

    // 选取n条边（共n+1个节点）
    for(int i = 0; i < n; i++) {
        int min_edge = INF;
        int k = -1;

        // 找到最小的边
        for(int j = 0; j <= n; j++) {
            if(!visited[j] && lowcost[j] < min_edge) {
                min_edge = lowcost[j];
                k = j;
            }
        }

        if(k == -1) break;  // 不连通
        visited[k] = true;
        total += lowcost[k];

        // 更新lowcost
        for(int j = 0; j <= n; j++) {
            if(!visited[j] && graph[k][j] < lowcost[j]) {
                lowcost[j] = graph[k][j];
            }
        }
    }

    return total;
}

int main(){
    int n, m, c;
    cin >> n >> m >> c;

    // 初始化邻接矩阵
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    // 读入每个村子建站的价格，作为虚拟节点0到该村子的边权
    for(int i = 1; i <= n; i++) {
        cin >> graph[0][i];
        graph[i][0] = graph[0][i];
    }

    // 读入原图的边，权值设为c*w
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        int cost = c * w;
        graph[u][v] = cost;
        graph[v][u] = cost;
    }

    // 使用Prim算法生成最小生成树（包含虚拟节点0）
    int res = prim(n);

    cout << res << endl;
    return 0;
}