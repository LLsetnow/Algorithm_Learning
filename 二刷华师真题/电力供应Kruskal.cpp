#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;
struct Edge{
    int u, v;
    int w;
};

Edge edges[MAXN + MAXM];
int p[MAXN];    // 并查集的父节点
// 查找并查集的根节点
int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);   // 路径压缩
}

// 返回最小生成树的最终代价
int Kruskal(int n, int m){
    // 初始化并查集
    for(int i = 0; i <= n; i++) p[i] = i;   // 初试指向自己
    // 边 按代价升序排序
    sort(edges+1, edges+1+m, [](Edge &a, Edge &b){
        return a.w < b.w;
    });

    int res = 0;    // 最小代价（距离）
    // 核心思路： 升序枚举所有边，若边两端的顶点 分别处于两个不同的联通分量，则合并这两个连通分量
    for(int i = 1; i <= m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(Find(u) != Find(v)){
            res += w;
            p[Find(u)] = Find(v);
        }
    }
    return res;
}
// 20min 通过20%
int main(){
    int n, m, c;    //村子数，道路数，电线每公里单价
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        // 将电站变为虚拟0号节点
        edges[m + i].u = 0;
        edges[m + i].v = i;
        edges[m + i].w = x;
    }

    // 最小生成树 边长[1-m]
    for(int i = 1; i <= m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w *= c;
    }

    //Kruskal
    // 将新建的电站 虚拟为0号节点， 
    // 第一个电站的费用，相当于 该电站所在节点 到 0号节点的代价 
    // 第二个电站的费用，相当于 该电站所在节点 到 0号节点的代价 
    // 边edges[1-m+n]
    // 节点[0-n]
    cout << Kruskal(n, m+n);

}