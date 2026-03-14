#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 102;
const int INF = 1e9 + 5;
char graph[MAXN][MAXN];  // 0墙壁 1起点 2路 3出口
int visited[MAXN][MAXN];  // 0 未访问 1 已访问
struct Point{
    int r, c;
    int step;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(Point start){
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    q.push(start);
    visited[start.r][start.c] = 1;
    int res = -1;
    while(!q.empty()){
        Point cur = q.front();
        q.pop();
        // 找到终点
        if(graph[cur.r][cur.c] == 'E'){
            res = cur.step;
            break;
        }
        // 尝试4个方向
        for(int i = 0; i < 4; i++){
            Point next;
            next.r = cur.r + dr[i];
            next.c = cur.c + dc[i];
            next.step = cur.step + 1;
            // 可以走 且 未访问
            if((graph[next.r][next.c] == '*' || graph[next.r][next.c] == 'E')
                && visited[next.r][next.c] == 0){
                    q.push(next);
                    visited[next.r][next.c] = 1;
                }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;;
    while(cin >> H >> W){
        Point cur;
        memset(graph, 0, sizeof(graph));
        if(H == 0 && W == 0) break;
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                cin >> graph[i][j];
                if(graph[i][j] == 'S'){
                    cur.r = i;
                    cur.c = j;
                    cur.step = 0;
                } 
            }
        }
        printf("%d\n", bfs(cur));
    }

}