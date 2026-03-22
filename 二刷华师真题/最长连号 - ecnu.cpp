#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    // 双指针找最长上升字段
    int l = 1, r = 2;
    int res = 1;
    while(l <= n && r <= n){
        if(a[r] - a[r - 1] != 1){
            res = max(res, r - l);
            l = r;
        }
        r++;
    }

    // 处理最后一组
    res = max(res, r - l);
    cout << res;
}