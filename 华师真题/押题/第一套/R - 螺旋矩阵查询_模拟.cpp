#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e9 + 5;
const int INF = 1e9 + 5;

struct Point{
    int r, c;
};

bool check(vector<Point> &targets, Point cur, vector<int> &res, int value){
    bool find = false;
    for(int i = 0; i < targets.size(); i++){
        if(targets[i].r == cur.r && targets[i].c == cur.c && res[i] == 0){
            res[i] = value;
            find = true;
        }
    }
    return find;
}
int main(){
    int row, col;
    cin >> row >> col;
    int T;
    cin >> T;
    vector<Point> targets;
    int T_copy = T;  // 保存原始值
    while(T_copy--){
        Point target;
        cin >> target.r >> target.c;
        targets.push_back(target);
    }


    // 设置边界 
    int R = col;
    int L = 1;
    int U = 1;
    int D = row;

    int dir = 0;
    int value = 0;
    vector<int> res(T, 0);  // 初始化为0
    int cnt = 0;
    while(true){
        // 向右
        for(int i = L; i <= R; i++){
            value++;
            Point cur;
            cur.r = U, cur.c = i;
            if(check(targets, cur, res, value)) cnt++;
        }
        if(++U > D || cnt == T) break;  // 更新边界 + 结束判断

        // 向下
        for(int i = U; i <= D; i++){
            value++;
            Point cur;
            cur.r = i, cur.c = R;
            if(check(targets, cur, res, value)) cnt++;
        }
        if(--R < L || cnt == T) break;  // 更新边界 + 结束判断

        // 向左
        for(int i = R; i >= L; i--){
            value++;
            Point cur;
            cur.r = D, cur.c = i;
            if(check(targets, cur, res, value)) cnt++;
        }
        if(--D < U || cnt == T) break;  // 更新边界 + 结束判断

        // 向上
        for(int i = D; i >= U; i--){
            value++;
            Point cur;
            cur.r = i, cur.c = L;
            if(check(targets, cur, res, value)) cnt++;
        }
        if(++L > D || cnt == T) break;  // 更新边界 + 结束判断
    }

    for(int i = 0; i < T; i++){
        cout << res[i] << endl;
    }
}
