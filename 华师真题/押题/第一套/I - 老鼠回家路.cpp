#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e4;
int graph[N][N] = {-1};
int maxRow = 0;
int maxCol = 0;

// 方向 ：占位、上、下、左、右 （方向0不用）
int dirR[] = {0, -1, 1, 0, 0};
int dirC[] = {0, 0, 0, -1, 1};
struct point
{
    int row;
    int col;
};

point GetNewPos(point p, int dir, int step){
    point q;
    q.row = p.row + step * dirR[dir];
    q.col = p.col + step * dirC[dir];
    maxRow = max(maxRow, q.row);
    maxCol = max(maxCol, q.col);
    return q;
}

point RecordPos(point p, int dir, int step){
    point q = p;
    while(step--){
        q.row += dirR[dir];
        q.col += dirC[dir];
        graph[q.row][q.col] = 1;

        maxRow = max(maxRow, q.row);
        maxCol = max(maxCol, q.col);
    }
    return q;
}

int main(){
    string s;
    vector<int> dirs;
    vector<int> steps;
    point pos = {10, 10};         // 以{10, 10}为起点
    point posNext = {10, 10};
    graph[10][10] = 2;   // 表示起点
    while(cin >> s){
        int dir = s[0] - '0';
        int step = s[2] - '0';
        if(dir == 0 && step == 0){
            graph[pos.row][pos.col] = 3;    // 表示终点
            break;
        }
        dirs.push_back(dir);
        steps.push_back(step);
        // posNext = GetNewPos(pos, dir, step);s
        posNext = RecordPos(pos, dir, step);
        //cout << dir << " " << step << endl;
    }

    for(int i = 0; i <= maxRow; i++){
        for(int j = 0; j <= maxCol; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

}