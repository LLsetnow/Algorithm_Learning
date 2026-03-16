#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1005;

int main(){
    int n, m, k;    // n米街道 m个街灯 照亮k米
    while(cin >> n >> m >> k){
        int pre = 0;    // 上一盏灯的照亮终点
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            int x;
            cin >> x;
            // 检查是否有空隙需要补充灯
            if(x - k > pre){
                int gap = x - k - pre - 1;
                if(k > 0){
                    cnt += (gap + 2*k - 1) / (2*k);
                } else {
                    cnt += gap;  // k=0时每盏灯照亮0米，需要gap盏灯
                }
            }
            pre = x + k;
        }

        // 检查最后一盏灯是否覆盖到终点
        if(pre < n){
            int gap = n - pre;
            cnt += (gap + 2*k - 1) / (2*k);
        }

        cout << cnt << endl;
    }
}