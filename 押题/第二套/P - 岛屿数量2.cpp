#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int G[MAXN][MAXN];  // 1陆地 0 水
int visited[MAXN][MAXN];

// 上下左右
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
struct Point{
    int r,c;
};
int main(){
    int row, col;
    cin >> row >> col;
    memset(G, 0, sizeof(G));
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= row; i++){
        string line;
        cin >> line;
        for(int j = 1; j <= col; j++){
            G[i][j] = line[j-1] - '0';
        }
    }

    int res = 0;
    // bfs 找岛屿数量
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            // 发现新岛屿
            if(G[i][j] == 1 && visited[i][j] == 0){

                res++;
                // 队列初始化
                visited[i][j] = 1;
                queue<Point> q;
                q.push({i, j});

                // bfs搜索
                while(!q.empty()){
                    Point cur = q.front();
                    q.pop();
                    // 尝试4个方向
                    for(int k = 0; k < 4; k++){
                        Point next;
                        next.r = cur.r + dr[k]; 
                        next.c = cur.c + dc[k]; 
                        // 越界判断
                        if(next.r > row || next.r < 1 || next.c > col || next.c < 1) continue;
                        if(G[next.r][next.c] == 1 && visited[next.r][next.c] == 0){
                            q.push(next);
                            visited[next.r][next.c] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}