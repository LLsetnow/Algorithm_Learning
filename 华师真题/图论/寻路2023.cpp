#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int num;    // 结点号
    int w;      // 边长度
    int max;    // 路径上最大边长
    int sum;    // 路径综合
    int sum_sub;// 路径变0后的综合最短长度
};

int main(){

    int N, M;
    cin >> N >> M;
    int Graph[N][N];
    memset(Graph, 0, sizeof(Graph));

    // 记录为邻接矩阵
    for(int i = 0; i < M; i++){
        int x, y, w;
        cin >> x >> y >> w;
        Graph[x - 1][y - 1] = w;
    }
    // 队列初始化（从结点0出发）
    queue<Node> q;
    for(int i = 1; i < N; i++){
        if(Graph[0][i]){
            Node node;
            node.num = i;
            node.w = Graph[0][i];
            node.max = Graph[0][i];
            node.sum = Graph[0][i];
            // 将路径上的最长边变0后的最短路径
            node.sum_sub = node.sum - node.max;
            q.push(node);
        }
    }
    // -10 后的最短路径
    int min_w = INT32_MAX;
    
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        for(int i = 0; i < N; i++){
            if(Graph[node.num][i]){
                Node newNode;
                newNode.num = i;
                newNode.w = Graph[node.num][i];
                newNode.max = max(node.max, newNode.w);
                newNode.sum = node.sum + newNode.w;
                newNode.sum_sub = newNode.sum - newNode.max;
                if(i == N - 1){
                    min_w = min(min_w, newNode.sum_sub);
                }
                q.push(newNode);
            }
        }
    }
    cout << min_w;
}