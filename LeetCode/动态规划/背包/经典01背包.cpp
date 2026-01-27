/*
01背包问题可描述为如下问题：
有一个容量为V的背包，还有n个物体。现在忽略物体实际几何形状，我们认为只要背包的剩余容量大于等于物体体积，那就可以装进背包里。每个物体都有两个属性，即体积w和价值v。
问：如何向背包装物体才能使背包中物体的总价值最大？

例
物体  重量 价值
A       2   3 
B       3   5
C       4   6
背包容量 = 6
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct 
{
    int w;
    int v;
} Item;

int bag(){
    vector<Item> items = {
        {2, 3},
        {3, 5},
        {4, 6}
    };
    int capacity = 6;
    // 注意行列都+1
    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i < items.size() + 1; i++){
        for(int j = 1; j < capacity + 1; j++){
            if(j < items[i - 1].w){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].w] + items[i - 1].v);
            }
        }
    }
    return dp[items.size()][capacity];
}

// 递归写法
int knapsack(const vector<Item>& items, int capacity, int index){
    if(index < 0 || capacity <= 0) return 0;
    if(capacity < items[index].w) return knapsack(items, capacity, index - 1);
    return max(knapsack(items, capacity, index - 1), knapsack(items, capacity - items[index].w, index - 1) + items[index].v);
}

int main(){
    cout << bag() << endl;
    cout << knapsack({{2, 3}, {3, 5}, {4, 6}}, 6, 2) << endl;
    return 0;
}