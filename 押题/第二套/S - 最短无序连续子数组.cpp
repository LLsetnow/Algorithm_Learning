#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int a[MAXN];
int b[MAXN];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    // 找到最短 非升序数组的长度
    
    // 将数组升序排列, 比较原数组
    sort(b + 1, b + 1 + n);
    int l = n + 1, r = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            l = min(l, i);
            r = max(r, i);
        }
    }

    cout << r - l + 1;
}