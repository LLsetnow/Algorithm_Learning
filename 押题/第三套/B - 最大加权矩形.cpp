#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 125;
const int INF = 1e9;
int a[MAXN][MAXN];
int s[MAXN][MAXN];


// 查询矩形和
int getSum(int r1, int c1, int r2, int c2){
    return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    memset(s, 0, sizeof(s));
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    int res = -INF;
    // 上边界
    for(int i = 1; i <= n; i++){
        // 下边界
        for(int j = i; j <= n; j++){

        }
    }
    cout << res;


}
