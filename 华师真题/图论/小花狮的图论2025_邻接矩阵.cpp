/*

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 5;
const int MAXN = 1e4 + 5;


int graph[MAXN][MAXN];  // 邻接矩阵存储图
int closest[MAXN];      // MST中 与节点i连接最近的点是closest[i]

// prim 返回最小生成树的代价 下标均为[1-based]
int prim(int n){
    int sum = 0;            // 总代价
    int lowcost[MAXN];      // lowcost[i]表示节点i到已加入MST的节点集合的最小距离
    // 默认选择顶点1为起点
    for(int i = 1; i <= n; i++){
        if(i == 1) lowcost[i] = 0;      // 代价为0 表示该点 已经添加到 最小树中
        else lowcost[i] = graph[1][i];  // 初始化所有点到 最小树的代价（无连接的点为INF）
        closest[i] = 1;                 // 初始都连接到点1
    }

    // 选择代价最小的点 要进行n-1次
    for(int i = 2; i <= n; i++){
        int idx = -1;       // 记录最近点的编号
        int minDist = INF;  // 记录最近距离
        // 找点
        for(int j = 1; j <= n; j++){
            if(lowcost[j] != 0 && lowcost[j] < minDist){
                // 当前点不在树中 且 距离最近
                minDist = lowcost[j];
                idx = j;
            }
        }
        // 记录点
        lowcost[idx] = 0;
        sum += minDist;
        // 更新lowcost[] (根据与 点idx相邻的点和边代价)
        for(int j = 1; j <= n; j++){
            int dist = graph[idx][j];
            if(dist < lowcost[j]){
                lowcost[j] = dist;
                closest[j] = idx;  // 记录j点连接到idx点（每次更新连接最近的点）
            }
        }
    }
    return sum;
}
int main(){
    int n;  // 点
    int m;  // 边
    cin >> n >> m;
    // 默认距离为无穷远
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            graph[i][j] = INF;
    
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int sumCost = prim(n);
    int maxSave = -1;  // 特殊操作的最大节约量
    for(int i = 2; i <= n; i++){
        int preCost = graph[i][closest[i]];
        int nowCost = i & closest[i];
        int save = preCost - nowCost;
        maxSave = max(maxSave, save);
    }
    // 特殊操作能减少cost
    if(maxSave > 0) sumCost -= maxSave;
    cout << sumCost;

}