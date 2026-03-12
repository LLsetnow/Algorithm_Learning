/*
小花拥有一个无向图，个点，条边，每一条边有对应的代价，你需要从中选出一些边，使得所有点两两可达，并且代价最小；某一天小花狮子获得了超能力，可以将某一条边的权值改为两端点的标号与，形式化地说即为：边代价更改为，最多操作一次，也可以选择不操作，你需要求出最终使得所有点两两可达的最小代价。

输入输出格式
输入描述:
第一行：两个整数，代表点数与边数。
第二行至第行：一行三个整数，代表点和直接有一条代价为的无向边。
输出描述:
一行，一个整数，代表最终使得所有点两两可达的最小代价。
输入输出样例
输入样例#:

4 5
1 2 10
2 3 8
3 4 12
1 4 20
2 4 15

输出样例#:
复制

18

提示
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 5;
const int MAXN = 1e5 + 5;

struct Edge{
    int u, v;
    ll w;
    ll savedCost; // 适用特殊方法的代价
};

Edge edges[MAXN];   // 记录边
int p[MAXN];        // 记录每个节点的父节点

// 查找节点x所在并查集的 根节点（带路径压缩）
int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]); // 路径压缩：将路径上的所有节点直接指向根节点
}
// Kruskal(克鲁斯卡尔) 最小生成树
ll Kruskal(int n, int m){
    ll sumCost = 0;
    ll maxSave = -1;
    // 按边权升序排序
    sort(edges + 1, edges + m + 1, [](Edge &a, Edge &b){
        return a.w < b.w;
    });
    // 并查集初始化
    for(int i = 1; i <= n; i++) p[i] = i;   // 根节点指向自己
    // 枚举每一条边
    for(int i = 1; i <= m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        ll savedCost = edges[i].savedCost;
        // 如果该边连接的两个节点不在同一个 连通分量（并查集）则合并
        if(Find(u) != Find(v)){
            // 合并连通分量（让一个连通分量的根 指向另一个的根）
            p[Find(u)] = Find(v);
            sumCost += w;
            maxSave = max(maxSave, w - savedCost);
        }
    }
    if(maxSave > 0) sumCost -= maxSave;
    return sumCost;
}

int main(){
    int n;  // 点
    int m;  // 边
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].savedCost = edges[i].u & edges[i].v;
    }
    cout << Kruskal(n, m);

}