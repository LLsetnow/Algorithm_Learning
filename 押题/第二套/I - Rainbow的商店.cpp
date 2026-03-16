/*
Rainbow开了一家商店，在一次进货中获得了N个商品。

已知每个商品的利润和过期时间。

Rainbow每天只能卖一个商品，并且过期商品不能再卖。

Rainbow也可以选择在每天出售哪个商品，并且一定可以卖出。

由于这些限制，Rainbow需要制定一份合理的售卖计划。请你计算一下，Rainbow最终可以获得的最大收益。
输入输出格式
输入描述:
第一行两个整数N。
接下来N行每行两个整数，分别表示每个商品的利润、过期时间。

1<=N,利润,时间<=10000。
输出描述:
输出一个整数，表示Rainbow最终可以获得的最大收益。
输入输出样例
输入样例#:

7
20 1
2 1
10 3
100 2
8 2
5 20
50 10

输出样例#:
复制

185

提示
第1天卖出20
第2天卖出100
第3天卖出10
第4天卖出50（实际上只要在第10天卖就可以）
第5天卖出5（实际上只要在第20天前卖就可以）
总计185
其它2件商品由于过期、每天只能卖一个的限制，在最优策略下应该不出售。

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

int main(){

    int n; cin >> n;
    memset(goods, 0, sizeof(goods));
    int lateDate = -1;
    for(int i = 1; i <= n; i++){
        cin >> goods[i].profit >> goods[i].date;
        lateDate = max(lateDate, goods[i].date);
    }
    // 排序：优先 按照保质期降序，其次按照利润降序
    sort(goods + 1, goods + 1 + n, [](Goods &a, Goods &b){
        if(a.date == b.date) return a.profit > b.profit;
        return a.date > b.date;
    }); 

    // 打印goods
    // for(int i = 1; i <= n; i++){
    //     cout << "id :" << i <<  " profit: " << goods[i].profit << " date: " << goods[i].date << endl;
    // }

    ll res = 0;
    int idx = 1;    // 开始查询的商品起点
    // 贪心策略：倒着卖东西，最后一天，从所有可以卖的东西里卖掉利润最高的。
    // 通过83%
    for(int i = lateDate; i > 1; i--){
        // cout << "date :" << i << endl;
        for(int j = idx; j <= n; j++){
            if(i <= goods[j].date){
                // 卖掉了
                // cout << "sold: " << j << " profit + " << goods[j].profit << endl;
                res += goods[j].profit;
                idx++;
                break;  // 一天只能卖一件
            }
            else{
                // 后面的商品保质期都不符合
                break;
            }
        }
    }   
    int maxProfit = 0;
    // 最后一天从所有合法的商品中选择价值最高的; 没有则+0
    for(int i = idx; i <= n; i++){
        maxProfit = max(maxProfit, goods[i].profit);
    }
    res += maxProfit;
    cout << res;
}

/*
            // 最后一天从所有合法的商品中选择价值最高的
            if(i == 1){

            }
*/