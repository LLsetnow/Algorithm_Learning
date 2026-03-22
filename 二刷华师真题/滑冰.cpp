/*
一个很滑的二维网格中存在冰块障碍，问你是否能从给定位置开始，最终停在终点。图中'#'为障碍，'.'为空地。
由于场地很滑，每次往上下左右移动都会撞上障碍才停止，并且每次开始移动后，移动的起点会生成一个新的冰块障碍。
输出到达终点的最小移动次数，如果不能到达终点则输出-1。

输入描述:
第一行为n,m——网格行数、列数
然后n行是n*m的二维网格
最后一行是起点坐标和终点坐标。
输出描述:
输出结果

输入输出样例
输入样例#:

3 5
#####
#.#
#####
2 2 2 4

输出样例#:
复制

-1

*/


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;
struct Point{
    int r;
    int c;
    int step;  // 步数
};
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int graph[MAXN][MAXN];
int vis[MAXN][MAXN];
int rows, cols;

int bfs(Point start, Point end) {
    queue<Point> q;
    q.push({start.r, start.c, 0});
    // 注意：起点不立即标记为障碍，而是在被取出时才标记

    while(!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 到达终点
        if(cur.r == end.r && cur.c == end.c) {
            return cur.step;
        }

        // 当前位置作为移动起点，生成障碍
        vis[cur.r][cur.c] = 1;

        // 向四个方向尝试滑动
        for(int d = 0; d < 4; d++) {
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];

            // 检查初始方向是否有效（不受vis影响）
            if(nr < 1 || nr > rows || nc < 1 || nc > cols || graph[nr][nc] == 1) continue;

            // 模拟滑行直到碰到原始障碍或边界（不受vis影响）
            int cr = nr, cc = nc;
            while(cr >= 1 && cr <= rows && cc >= 1 && cc <= cols && graph[cr][cc] == 0) {
                cr += dr[d];
                cc += dc[d];
            }

            // 回退到合法位置（最后一次有效位置）
            cr -= dr[d];
            cc -= dc[d];

            // 如果是终点，直接返回
            if(cr == end.r && cc == end.c) {
                return cur.step + 1;
            }

            // 如果没有移动或已访问，跳过
            if((cr == cur.r && cc == cur.c) || vis[cr][cc]) continue;

            // 加入队列，但不要立即标记为障碍
            q.push({cr, cc, cur.step + 1});
        }
    }

    return -1;  // 无法到达
}

int main(){
    cin >> rows >> cols;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= cols; j++){
            char ch;
            cin >> ch;
            if(ch == '#') graph[i][j] = 1;  // 障碍
            else graph[i][j] = 0;           // 空地
        }
    Point start, end;
    cin >> start.r >> start.c >> end.r >> end.c;

    int result = bfs(start, end);
    cout << result << endl;

    return 0;
}
