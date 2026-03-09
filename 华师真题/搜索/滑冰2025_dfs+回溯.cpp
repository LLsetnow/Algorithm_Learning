/*
一个很滑的二维网格中存在冰块障碍，问你是否能从给定位置开始，最终停在终点。图中‘#’为障碍，‘.’为空地。
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
#.#.#
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
};
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int graph[MAXN][MAXN];
int vis[MAXN][MAXN];
int minStep = INT_MAX;

void dfs(Point pos, Point end, int step) {
    // 成功回溯
    if(pos.r == end.r && pos.c == end.c) {
        minStep = min(minStep, step);
        return;
    }
    // 尝试4个方向
    for(int d = 0; d < 4; d++) {
        int nr = pos.r + dr[d];
        int nc = pos.c + dc[d];

        // 非法位置 或 该方向有障碍
        if(nr < 1 || nr > pos.r || nc < 1 || nc > pos.c || vis[nr][nc]) continue;

        // 模拟滑行直到碰到障碍
        int cr = nr, cc = nc;
        while(cr >= 1 && cr <= pos.r && cc >= 1 && cc <= pos.c && graph[cr][cc] == 0) {
            cr += dr[d];
            cc += dc[d];
        }

        // 回退到合法位置
        cr -= dr[d];
        cc -= dc[d];

        if((cr == pos.r && cc == pos.c) || vis[cr][cc]) continue;

        vis[cr][cc] = 1;
        dfs({cr, cc}, end, step + 1);
        vis[cr][cc] = 0;
    }
}

int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++){
            char ch;
            cin >> ch;
            if(ch == '#') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    Point start, end;
    cin >> start.r >> start.c >> end.r >> end.c;

    // 起点设为障碍
    vis[start.r][start.c] = 1;
    dfs(start, end, 0);

    if(minStep == INT_MAX) cout << -1 << endl;
    else cout << minStep << endl;

    return 0;
}
