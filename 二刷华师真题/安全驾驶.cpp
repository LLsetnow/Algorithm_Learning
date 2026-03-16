#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1005;
int a[MAXN];

// 耗时：7 min; 
// 求出其他车到达目的地的耗时，取其中的最大耗时，d / 最大耗时 = 安全速度
int main(){
    int d; cin >> d;
    int n; cin >> n;
    memset(a, 0, sizeof(a));

    double maxTime = 0;
    for(int i = 1; i <= n; i++){
        int k, v;
        cin >> k >> v;
        if(k > d) continue;
        k = d - k;
        double time = k * 1.0 / v;
        maxTime = max(maxTime, time);
    }
    printf("%.6f", d / maxTime);

}