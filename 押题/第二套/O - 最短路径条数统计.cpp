#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1005;
const int MAXM = 10005;
const int INF = 1e9;
int G[MAXN][MAXN];
int dist[MAXN];     // 起点到其他节点的最短距离
int visited[MAXN];  // 是否已经确认该点的最短距离
int cnt[MAXN];      // 起点到其他节点的最短路径条数
int n, m, s, t;     // n、m、s、t，分别表示节点数、边数、起点编号和终点编号

int Dijkstra(){
    // 初始化距离和路径条数
    for(int i = 1; i <= n; i++){
        if(G[s][i] != 0){
            dist[i] = G[s][i];
            cnt[i] = 1;  // 起点直接相连的点，路径条数为1
        } else {
            dist[i] = INF;
            cnt[i] = 0;
        }
    }
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;
    dist[s] = 0;
    cnt[s] = 1;  // 起点到自己的路径条数为1

    // 再找 n-1 次最近的点
    for(int i = 2; i <= n; i++){
        int idx = -1;
        int minDist = INF;
        for(int j = 1; j <= n; j++){
            if(visited[j] == 0 && dist[j] < minDist){
                idx = j;
                minDist = dist[j];
            }
        }
        if(idx == -1) break;    // 已经无法再找到可达的点

        // 记录最近的点
        visited[idx] = 1;
        // cout << "near point :" << idx << endl;

        // 更新距离和路径条数
        for(int j = 1; j <= n; j++){
            if(visited[j] == 0 && G[idx][j] != 0){
                int newDist = dist[idx] + G[idx][j];
                if(newDist < dist[j]){
                    // 找到更短的距离，更新距离和路径条数
                    dist[j] = newDist;
                    cnt[j] = cnt[idx];  // 继承idx的路径条数
                } else if(newDist == dist[j]){
                    // 距离相同，累加路径条数
                    cnt[j] += cnt[idx];
                }
            }
        }
    }
    if(dist[t] == INF) return 0;  // t不可达
    return cnt[t];  // 返回最短路径条数

}
int main(){
    cin >> n >> m >> s >> t;
    s++; t++;
    memset(G, 0, sizeof(G));
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        G[u][v] = w;
    }
    int cnt = Dijkstra();
    // 目标不可达
    if(cnt == 0){
        printf("-1 0\n");
    }
    else{
        printf("%d %d\n", dist[t], cnt);
    }

    return 0;

}