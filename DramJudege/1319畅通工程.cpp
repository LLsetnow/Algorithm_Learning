#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int p[MAXN];

int Find(int x){
    if(p[x] == x) return x;
    return p[x] = Find(p[x]); // 顺着父亲找根节点 + 路径压缩
}
// 计算连通域个数
int Count(int node){
    set<int> roots;
    for(int i = 1; i<= node; i++){
        roots.insert(Find(i));  //重复插入，会被忽略（set 自动去重）
    }
    return roots.size();
}
int main(){
    int node, edgeNum;
    while(cin >> node){
        if(node == 0) break;
        cin >> edgeNum;
        // 初始化 并查集
        for(int i = 1; i <= node; i++) p[i] = i;   // 根节点指向自己

        // 输入
        for(int i = 1; i <= edgeNum; i++){
            int u, v;
            cin >> u >> v;
            // 如果两个节点的根节点不同，合并两个并查集
            if(Find(u) != Find(v)){
                p[Find(u)] = Find(v);
            }
        }
        // 最后判断有多少个连通分量
        set<int> roots;
        for(int i = 1; i <= node; i++){
            roots.insert(Find(i));
        }
        // x 个连通分量，还需要 x - 1 条边连接为一个连通分量
        cout << (roots.size() - 1) << endl;
    }
}