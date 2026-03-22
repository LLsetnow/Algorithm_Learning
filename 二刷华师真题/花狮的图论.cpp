#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 105;
const int INF = 1e9;
// 最小生成树 记录最长的边 -> 魔法归零
// Kruskal

struct Edge{
    int u, v;
    int w;
};

//Kruskal
Edge edges[MAXN];
int p[MAXN];    // 归并集
int maxCost = 0;   // 记录选中的最大边长

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

ll Kruskal(int n, int m){
    // 初始化归并集合
    for(int i = 1; i <= n; i++) p[i] = i;

    // 边升序排序
    sort(edges + 1, edges + 1 + m, [](Edge &a, Edge &b){
        return a.w < b.w;
    });

    ll res = 0;

    // 枚举每一条边
    for(int i = 1; i <= m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        // 不在同一个 连通分量
        if(Find(u) != Find(v)){
            p[Find(u)] = Find(v);
            res += w;
            maxCost = max(maxCost, w - (u&v));
        }
    }

    return res;
}


// prim
int G[MAXN][MAXN];
int dist[MAXN];
int visited[MAXN];

int Prim(int n, int m){
    // 初始化 选择 1为起点
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        dist[i] = G[1][i];  // 不可达的点 为INF
    }
    visited[1] = 1;
    int res = 0;
    // 选择n-1条边
    for(int i = 2; i <= n; i++){
        int minD = INF;
        int idx = -1;

        for(int j = 1; j <= n; j++){
            if(visited[j] == 0 && dist[j] < minD){
                minD = dist[j];
                idx = j;
            }
        }

        // 如果找不到节点 图不连通
        if(idx == -1) return -1;

        // 将idx节点加入MST
        visited[idx] = 1;
        res += minD;
        maxCost = max(maxCost, minD);

        // 更新最近距离
        for(int j = 1; j <= n; j++){
            int newD = G[idx][j];
            if(visited[j] == 0 && newD < dist[j]){
                dist[j] = newD;
            }
        }
    }
    return res;
}


/*
    逻辑错了，不应该是 最小生成树代价 - 最短边的代价
*/
int main(){
    int n, m;   // 点，边
    cin >> n >> m;


    // Kruskal
    for(int i = 1; i <= m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    // 最小生成树代价 - 最长选中的代价
    // 超时 通过33%
    cout << Kruskal(n, m) - maxCost;

    // Prim
    // memset(G, 0x3f, sizeof(G));
    // for(int i = 1; i <= m; i++){
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     G[u][v] = w;
    //     G[v][u] = w;
    // }
    // cout << Prim(n, m) - maxCost;
}