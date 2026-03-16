/*
给定一个有向图，包含 `n` 个节点和 `m` 条有向边，每条边带有一个整数权重（可正可负）。指定起点 `S` 和终点 `T`，请计算从 `S` 到 `T` 的最长路径长度。若存在以下情况之一，输出 `-1`：
1. 从 `S` 无法到达 `T`；
2. 从 `S` 到 `T` 的路径中包含环（导致最长路径长度无穷大）。

方法：使用Bellman-Ford算法求最长路径，并检测正环
策略：
1. 将所有边权取反，求最短路径
2. 如果存在负环，则原图存在正环，输出-1
3. 松弛n次后，如果还能松弛，说明有环
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 5005;
const int INF = 1e9;

struct Edge{
    int u, v, w;
};

Edge edges[MAXM];
int dist[MAXN];

// Bellman-Ford算法：求最长路径（通过取反求最短路径）
// 返回值：是否有环
bool bellmanFord(int n, int m, int start){
    // 初始化
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    dist[start] = 0;

    // 松弛n-1次
    for(int i = 1; i <= n - 1; i++){
        bool updated = false;
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u] != INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if(!updated) break;  // 提前退出
    }

    // 检查是否有环（还能松弛说明有环）
    for(int j = 0; j < m; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if(dist[u] != INF && dist[v] > dist[u] + w){
            return true;  // 有环
        }
    }
    return false;  // 无环
}

int main(){
    int n, m, start, target;
    cin >> n >> m >> start >> target;

    // 读取边，并取反（将最长路径转化为最短路径）
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w = -edges[i].w;  // 取反
    }

    // 检测是否有环
    if(bellmanFord(n, m, start)){
        cout << -1 << endl;
        return 0;
    }

    // 输出结果（记得取反回来）
    if(dist[target] == INF){
        cout << -1 << endl;
    }
    else{
        cout << -dist[target] << endl;
    }

    return 0;
}




