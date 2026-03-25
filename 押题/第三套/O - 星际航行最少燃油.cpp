/*
宇宙中有个星球（编号），星球之间存在条双向星际航线，通过任意一条航线都需要消耗固定量的燃油`cost`。
同时，星球存在引力场，途经任意星球时需要额外消耗该星球的引力燃油`gravity`（起点星球和终点星球的引力燃油无需消耗，仅途经星球计算）。
给定起点星球`start`和终点星球`end`，请计算从起点到终点的最少燃油总消耗量。若起点无法到达终点，输出。

注：
1. 航线为双向，燃油消耗仅计算一次航线cost；
2. 途经星球指路径中除起点、终点外的所有星球，每个途经星球仅计算一次其gravity燃油；
3. 燃油消耗（航线cost+引力gravity）均为正整数，不存在负消耗情况；
4. 若起点与终点为同一个星球，燃油总消耗为。
输入输出格式
输入描述:
第一行输入两个整数，分别表示星球数量和航线数量（，）；
第二行输入个整数，其中表示编号为的星球的引力燃油消耗（）；
接下来行，每行输入三个整数，表示星球和星球之间存在一条双向航线，通过该航线需消耗燃油（）；
最后一行输入两个整数，表示起点和终点星球编号（）。
输出描述:
输出一个整数，表示从起点到终点的最少燃油总消耗量，无法到达则输出。
输入输出样例
输入样例#:

5 6
2 3 5 1 4
0 1 2
0 2 5
1 2 1
1 3 3
2 4 2
3 4 4
0 4

输出样例#:
复制

12



*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 5005;
const int INF = 1e9;
int G[MAXN][MAXN];
int cost[MAXN];


int dist[MAXN];
int visited[MAXN];
int n, m, s, t;

int DijKtra(){
    for(int i = 0; i < n; i++){
        dist[i] = G[s][i] == 0 ? INF : (G[s][i] + cost[i]);
    }
    // cout << "dist: ";
    // for(int i = 0; i < n; i++){
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;

    // 在找n-1次最近的点
    for(int i = 1; i < n; i++){
        int idx = -1;
        int minDist = INF;
        for(int j = 0; j < n; j++){
            if(visited[j] == 0 && dist[j] < minDist){
                minDist = dist[j];
                idx = j;
            }
        }
        if(idx == -1) return -1; // 无法到达
        if(idx == t) break;

        // 记录最近的点
        visited[idx] = 1;
        // cout << "choose " << idx << endl;

        // 更新距离
        for(int j = 0; j < n; j++){
            int newDist = dist[idx] + G[idx][j] + cost[j];
            if(visited[j] == 0 && G[idx][j] != 0 && newDist < dist[j]){
                dist[j] = newDist;
            }
            // cout << dist[j] << " ";
        }
        // cout << endl;
    }
    if(dist[t] == INF) return -1;
    return dist[t] - cost[t];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    cin >> s >> t;
    cout <<  DijKtra() << endl;
    return 0;
}