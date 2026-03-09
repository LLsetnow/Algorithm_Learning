/*
最小生成树 - Prim算法模板
时间复杂度: O(n²) - 使用邻接矩阵
空间复杂度: O(n²)

适用场景:
- 稠密图（边数接近n²）
- 需要快速实现
- 节点数n ≤ 1000
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int graph[MAXN][MAXN];  // 邻接矩阵存储图
bool visited[MAXN];     // 标记节点是否加入MST
int lowcost[MAXN];      // lowcost[i]表示节点i到已加入MST的节点集合的最小距离
int closest[MAXN];      // closest[i]表示节点i到MST最近的节点（用于记录MST的边）

// Prim算法 - 返回MST的总权值
// 如果图不连通，返回-1
int prim(int n, vector<pair<int,int>>& mstEdges) {
    // 初始化
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        lowcost[i] = graph[1][i];
        closest[i] = 1;
    }
    visited[1] = true;

    int total = 0;  // MST总权值

    // 选取n-1条边
    for(int i = 1; i < n; i++) {
        int min_edge = INF;
        int k = -1;

        // 找到距离MST最近的未访问节点
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && lowcost[j] < min_edge) {
                min_edge = lowcost[j];
                k = j;
            }
        }

        // 如果找不到节点，说明图不连通
        if(k == -1) return -1;

        // 将节点k加入MST
        visited[k] = true;
        total += lowcost[k];

        // 记录MST的边: closest[k] -> k, 权值为lowcost[k]
        mstEdges.push_back({closest[k], k});

        // 更新所有未访问节点到MST的最小距离
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && graph[k][j] < lowcost[j]) {
                lowcost[j] = graph[k][j];
                closest[j] = k;
            }
        }
    }

    return total;
}

// Prim算法简化版 - 只返回总权值，不记录边
int prim_simple(int n) {
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        lowcost[i] = graph[1][i];
    }
    visited[1] = true;

    int total = 0;
    for(int i = 1; i < n; i++) {
        int min_edge = INF;
        int k = -1;

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && lowcost[j] < min_edge) {
                min_edge = lowcost[j];
                k = j;
            }
        }

        if(k == -1) return -1;

        visited[k] = true;
        total += lowcost[k];

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && graph[k][j] < lowcost[j]) {
                lowcost[j] = graph[k][j];
            }
        }
    }

    return total;
}

// 读取输入并初始化图
void init_graph(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;  // 默认无边
            }
        }
    }
}

int main() {
    int n, m;
    cout << "输入节点数n和边数m: ";
    cin >> n >> m;

    // 初始化图
    init_graph(n);

    cout << "输入" << m << "条边 (格式: u v w):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;  // 无向图
    }

    // 计算最小生成树
    vector<pair<int,int>> mstEdges;
    int result = prim(n, mstEdges);

    if(result == -1) {
        cout << "图不连通，无法生成最小生成树！" << endl;
    } else {
        cout << "最小生成树总权值: " << result << endl;
        cout << "最小生成树的边:" << endl;
        for(auto& edge : mstEdges) {
            cout << edge.first << " -> " << edge.second << endl;
        }
    }

    return 0;
}

/*
使用示例:

输入:
3 3
1 2 1
2 3 1
1 3 3

输出:
最小生成树总权值: 2
最小生成树的边:
1 -> 2
2 -> 3


算法流程:
1. 从任意节点开始（这里选择节点1）
2. 重复以下步骤n-1次:
   a. 找到未访问节点中距离MST最近的节点k
   b. 将k加入MST，累加边权到总权值
   c. 更新所有未访问节点到MST的最小距离

时间复杂度分析:
- 外层循环n-1次
- 每次循环需要O(n)时间找最小值和更新距离
- 总时间复杂度: O(n²)

优化方向:
- 使用优先队列可以优化到O(m log n)
- 但实现更复杂，适合稀疏图
*/
