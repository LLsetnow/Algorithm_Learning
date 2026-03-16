/*
这是一个贪心问题：每天只能卖一个商品，要最大化总利润。
策略：
1. 按利润从高到低排序
2. 对每个商品，尽量在过期当天卖；如果当天被占用，就往前找最近可用的天
3. 使用并查集快速查找可用的天
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e4 + 5;
struct Goods
{
    int profit;
    int date;
};

Goods goods[MAXN];
int parent[MAXN];  // 并查集：parent[i] 表示 i 之前最近的可用天

// 查找可用天（带路径压缩）
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main(){
    int n; cin >> n;
    memset(goods, 0, sizeof(goods));
    int lateDate = 0;
    for(int i = 1; i <= n; i++){
        cin >> goods[i].profit >> goods[i].date;
        lateDate = max(lateDate, goods[i].date);
    }

    // 按利润从高到低排序
    sort(goods + 1, goods + 1 + n, [](Goods &a, Goods &b){
        return a.profit > b.profit;
    });

    // 初始化并查集
    for(int i = 0; i <= lateDate; i++){
        parent[i] = i;
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
        // 只有根节点才是可用的天，使用过的天要指向空的天
        int day = find(goods[i].date);  // 找到可用的天
        if(day != 0){  // day=0 表示之前没有可用的天了
            res += goods[i].profit;
            parent[day] = find(day - 1);  // 标记这天已占用，下次查找时跳过
        }
    }

    cout << res;
    return 0;
}
