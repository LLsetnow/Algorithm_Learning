#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1005;

struct YuanZhu{
    ll r;
    ll h;
    ll ce;
};

YuanZhu zhu[MAXN];

// 耗时20min； 15min出暴力解 拿下80%
// 总表面积 = 最下面的上底面积 + 所有圆柱的侧面积之和
int main(){
    int n, k;
    cin >> n >> k;
    memset(zhu, 0, sizeof(zhu));
    for(int i = 1; i <= n; i++){
        cin >> zhu[i].r >> zhu[i].h;
        zhu[i].ce = 2 * zhu[i].r * zhu[i].h;
    }
    // 侧面积 降序
    sort(zhu + 1, zhu + 1 + n, [](YuanZhu &a, YuanZhu &b){
        return a.ce > b.ce;
    });

    ll sum = 0;
    ll maxR = -1; // 记录最大半径
    // 只取k个
    for(int i = 1; i <= k; i++){
        sum += zhu[i].ce;
        maxR = max(maxR, zhu[i].r);
    }
    // 检查剩余 n - k个圆柱中 有没有虽然侧面积小但 半径巨大的, 替换第k个
    ll maxUp = 0;   // 最大提升
    ll oldValue =  maxR * maxR + zhu[k].ce; // 原 最大半径平方 + 第k个侧面积
    for(int i = k + 1; i <= n; i++){
        ll newValue = zhu[i].r * zhu[i].r + zhu[i].ce;
        maxUp = max(maxUp, newValue - oldValue);
    }

    // 最下面的底面积
    sum += maxR * maxR + maxUp;
    cout << sum;

}