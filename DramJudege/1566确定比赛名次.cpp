#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;

int G[MAXN][MAXN];  // G[i][j] = 1 表示 i 战胜 j
int visited[MAXN];  // 0 表示未确定排名， 1 表示已确定排名
int main(){
    int n, m;
    while(cin >> n >> m){
        memset(G, 0, sizeof(G));
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            // 第i列 表示 第i队的前缀解锁条件；第i行 表示 第i队的后缀制约
            G[a][b] = 1;
        }
        queue<int> q;   // 没有前缀制约的队伍编号

        // 队列初始化
        for(int i = 1; i <= n; i++){
            int lock = 0;
            for(int j = 1; j <= n; j++){
                if(G[j][i] == 1) lock = 1;
            }
            if(lock == 0 && visited[i] == 0){
                visited[i] = 1;
                q.push(i);
                break;  // 每次只找一个无前缀的队伍，保证相同条件的队伍编号升序排列
            } 
        }
        while(!q.empty()){
            int top = q.front();
            printf("%d ", top);
            q.pop();
            // 解除 top队的后缀制约
            for(int j = 1; j <= n; j++){
                G[top][j] = 0;
            }

            // 检查可以加入队列的队伍
            for(int i = 1; i <= n; i++){
                int lock = 0;
                for(int j = 1; j <= n; j++){
                    if(G[j][i] == 1) lock = 1;
                }
                if(lock == 0 && visited[i] == 0){
                    visited[i] = 1;
                    q.push(i);
                    break;
                } 
            }
        }
        printf("\n");
    }


}