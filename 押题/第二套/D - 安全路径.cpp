/*

卫斯理小说经常提及外星人，比如蓝血人。 在土星星球有很多城市，每个城市之间有一条或多条飞行通道， 但是并不是所有的路都是很安全的，每一条路有一个安全系数 s,s 是在 0和1 间的实数 (包括 0 ， 1) ，一条从 u 到 v 的通道 P 的安全度为 Safe(P) = s(e1)*s(e2)…*s(ek) e1,e2,ek是P 上的边 ，现在蓝血人想出去旅游，面对这这么多的路，他想找一条最安全的路。但是蓝血人的数学不好，想请你帮忙 ^_^ --
输入输出格式
输入描述:
输入包括多个测试实例，每个实例包括： 
第一行： 一个整数 n。 n 表示城市的个数 n<=1000; 
接着是一个 n*n 的矩阵表示两个城市之间的安全系数， (0可以理解为那两个城市之间没有直接的通道 )。 
接着是一个整数m (m<=100)表示若干个蓝血人要旅游的路线 ,下面每行有两个数字，表示蓝血人所在的城市和要去的城市。
输出描述:
如果蓝血人无法达到他的目的地，输出 "What a pity!" ， 
其他的输出这两个城市之间的最安全道路的安全系数，保留三位小数。
输入输出样例
输入样例#:

3
1 0.5 0.5
0.5 1 0.4
0.5 0.4 1
3		
1 2
2 3
1 3

输出样例#:
复制

0.500
0.400
0.500


*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

double graph[MAXN][MAXN];

double lowcost[MAXN];    // 每个点到起点的最大安全系数(已做 边的乘积运算)
int visited[MAXN];      // 记录每个点是否已经缺点到起点的最大安全系数
// Dijkstra找最大安全系数
double Dijkstra(int n, int start, int target){
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++){
        lowcost[i] = graph[start][i];   // 不能直达，则初始值为0
    }
    lowcost[start] = 1; // 起点到自己 安全系数为1
    visited[start] = 1; // 起点到自己 已确认最大安全系数
    // 再找 n - 1 次点
    for(int i = 2; i <= n; i++){
        double saveK = 0;    // 寻找最大安全系数
        int saveIdx = -1;   // 记录最大安全系数的索引
        // 找最近的点
        for(int j = 1; j <= n; j++){
            if(visited[j] == 0 && lowcost[j] > saveK){
                saveK = lowcost[j];
                saveIdx = j;
            }
        }
        // 如果找不到更多可达点，退出
        if(saveIdx == -1) break;
        // 记录最近点
        visited[saveIdx] = 1;
        lowcost[saveIdx] = saveK;

        // 更新 更优安全系数
        for(int j = 1; j <= n; j++){
            double newSave = graph[saveIdx][j] * lowcost[saveIdx];
            if(visited[j] == 0){
                lowcost[j] = max(lowcost[j], newSave);
            }
        }
    }

    // 如果目标点不可达，返回 0
    return lowcost[target];
}

// Floyd算法求所有点对之间的最大安全系数
void Floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                // 通过中转点 k，从 i 到 j 的安全系数可能更大
                if(graph[i][k] > 0 && graph[k][j] > 0){
                    graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);
                }
            }
        }
    }
}
int main(){
    
    int n;
    while(cin >> n && n != 0){  // n=0 时结束
        memset(graph, 0, sizeof(graph));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> graph[i][j];
            }
        }
    
        int m; cin >> m;
        //  Floyd 预处理所有点
        Floyd(n);
        for(int i = 1; i <= m; i++){
            int start, target;
            cin >> start >> target;
    
            double ans = graph[start][target];
            if(ans == 0) printf("What a pity!\n");
            else printf("%.3lf\n", ans);

            // Dijkstra（每次查询 O(n²)）：
            // double ans = Dijkstra(n, start, target);
            // if(ans == 0) printf("What a pity!\n");
            // else printf("%.3lf\n", ans);
        }
    }
}