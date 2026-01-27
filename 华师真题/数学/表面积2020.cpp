/*
第 1 行：整数 n（1<=n<=1000）和 k（1<=k<=n），一个空格分隔。
第 n+1行：每个圆柱体的半径 Rcm与高度 Hcm（1<=R, H<=10^6），一个空格分隔。

思路：
    从 n 个圆柱中选 k 个，按半径从大到小叠放

    可见表面积组成：
    - 最下面圆柱：顶面 + 侧面积
    - 其余圆柱：仅侧面积

    
    因此只要选择最大的k个侧面积 在加上已选圆柱中 最大的顶面积(作为最下面的圆柱)
    但是,以上情况不一定正确,当没有被选的圆柱中,可能存在 顶面积非常大,但侧面积较小的圆柱
    考虑特殊情况:
        从已选的k个圆柱中,将侧面积最小的圆柱 替换为 未选的圆柱中半径最大的圆柱
    综上,只要比较常规情况计算所得值 和 特殊情况的值 输出较大值 即可
*/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Cylinder {
    i64 r, h;
    i64 sideArea;  // 侧面积 = 2 * pi * r * h
};

int main(){
    int n, k;
    cin >> n >> k;

    // 读入圆柱
    vector<Cylinder> cy(n);
    for(int i = 0; i < n; i++){
        cin >> cy[i].r >> cy[i].h;
        cy[i].sideArea = 2LL * cy[i].r * cy[i].h;
    }

    
    // 根据侧面积排序
    sort(cy.begin(), cy.end(), 
    [](const Cylinder &a, const Cylinder &b){
        return a.sideArea > b.sideArea;
    });
    
    i64 resA = 0;
    i64 resB = 0;
    i64 maxRFront = 0;
    i64 maxRIndex = k;
    i64 minSide = INT64_MAX / 2;

    for(int i = 0; i < n; i++){
        if(i < k){
            i64 sideArea = cy[i].sideArea;
            resA += sideArea;
            minSide = min(minSide, sideArea);
            maxRFront = max(maxRFront, cy[i].r); 
        }
        else{
            maxRIndex = cy[i].r > cy[maxRIndex].r ? i : maxRIndex;
        }
    }
    
    resB = resA - minSide + cy[maxRIndex].sideArea + cy[maxRIndex].r * cy[maxRIndex].r;
    resA += maxRFront * maxRFront;
    cout << max(resA, resB);
}
