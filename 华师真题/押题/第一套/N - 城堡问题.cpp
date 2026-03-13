/*
图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m×n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。
输入输出格式
输入描述:
程序从标准输入设备读入数据。第1、2行每行1个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。
输出描述:
输出2行，每行一个数，表示城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。
输入输出样例
输入样例#:

4
7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

输出样例#:
5
9
*/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 55;
int m, n;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

// 方向对应：西、北、东、南
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const int wall[4] = {1, 2, 4, 8};  // 西、北、东、南的墙值

int dfs(int i, int j) {
    visited[i][j] = true;
    int size = 1;
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
            // 如果当前格子在这个方向没有墙，则可以移动
            if ((grid[i][j] & wall[k]) == 0) {
                size += dfs(ni, nj);
            }
        }
    }
    return size;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int roomCount = 0;
    int maxRoom = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                int size = dfs(i, j);
                ++roomCount;
                if (size > maxRoom) maxRoom = size;
            }
        }
    }

    cout << roomCount << endl;
    cout << maxRoom << endl;
    return 0;
}