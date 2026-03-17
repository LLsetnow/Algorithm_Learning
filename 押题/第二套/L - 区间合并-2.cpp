#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100005;

struct Area{
    int l, r;
    bool deleted;
};

Area a[MAXN];
int main(){
    int n; cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].deleted = false;
    }
    // 先按照左端点位置升序排序, 其次右端点降序
    sort(a, a + n, [](Area &a, Area &b){
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });


    for(int i = 1; i < n; i++){
        // cout << "i = " << i << endl;
        // 找到上一个没有被删除的区间
        int pre = i - 1;
        while(pre >= 0 && a[pre].deleted) pre--;
        // 如果没有前一个区间，跳过
        if(pre < 0) continue;
        // 如果 区间i的左端点 <= 区间pre的右端点, 合并这两个区间
        // [1-8] [9-12] 这两个区间也要合并
        if(a[i].l <= a[pre].r + 1){
            int posR = max(a[i].r, a[pre].r);
            a[pre].r = posR;
            a[i].deleted = true;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i].deleted == false){
            // cout << a[i].l << " " << a[i].r << endl;
            printf("%d %d\n", a[i].l, a[i].r);
        }
    }

    return 0;

}