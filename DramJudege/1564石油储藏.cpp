/*
有一个GeoSurvComp地质勘探公司正在负责探测地底下的石油块。这个公司在一个时刻调查一个矩形区域，并且创建成一个个的格子用来表示众多正方形块。它然后使用测定设备单个的分析每块区域，决定是否有石油。一块有石油小区域被称为一个pocket，假设两个pocket是相邻的，然后他们就是相同石油块的一部分，石油块可能非常的大并且包涵很多的pocket。你的任务就是在一个网格中存在多少个石油块。输入首先给出图的大小，然后给出这个图。*代表没有石油，@代表存在石油。输出每种情况下石油块的个数。
输入输出格式
输入描述:
输入包含一个或多个网格。 每个网格都以包含m和n的行开始，网格中的行和列数为m和n，以单个空格分隔。 如果m = 0，则表示输入结束。 否则为1 <= m <= 100和1 <= n <=100。这之后是m行，每行n个字符（不计算行末字符）。 每个字符对应一个情节，要么是代表没有油的“ *”，要么是代表油囊的“ @”。
输出描述:
在水平，垂直或对角线上都算作相邻，输出每种情况下石油块的个数。

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char graph[MAXN][MAXN];  // [1-n] @有油 *没油
int visited[MAXN][MAXN]; // 0 未访问 n：属于n号油田[1-n]

// 上下左右、左上、左下、右上、右下
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
struct Point{
    int r, c;
};

void dfs(Point cur, int idx, int row, int col){
    for(int i = 0; i < 8; i++){
        Point next;
        next.r = cur.r + dr[i];
        next.c = cur.c + dc[i];
        if(next.r < 1 || next.r > row || next.c < 1 || next.c > col) continue;
        if(visited[next.r][next.c] == 0 && graph[next.r][next.c] == '@'){
            visited[next.r][next.c] = idx;
            dfs(next, idx, row, col);
        }
    }
    return;
}

int main(){
    int row, col;
    while(cin >> row >> col){
        if(row == 0 && col == 0) break;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                cin >> graph[i][j];
            }
        }
        int res = 0;
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                // 未被记录 且 有油
                if(visited[i][j] == 0 && graph[i][j] == '@'){
                    res++;
                    visited[i][j] = res;  // 先标记起点！
                    dfs({i, j}, res, row, col);
                }
            }
        }
        cout << res << endl;
    }
}