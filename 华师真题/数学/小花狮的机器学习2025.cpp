#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const int MAXM = 15;

ll a[MAXN];
ll A[MAXM][MAXM];

int CLIP(int score){
    if(score < 1) return 1;
    if(score > 7) return 7;
    return score;
}

int main(){

    int n; cin >> n;
    ll sum_a = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum_a += a[i];
    } 
        
    int m; cin >> m;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            cin >> A[i][j];
    
    // 计算Score
    ll score = 0;
    for(int i = 1; i <= n; i++){
        if(sum_a % a[i] == 0){
            score = max(score, a[i]);
        }
    }

    ll filter = CLIP(score);
    ll res = 1;
    for(int i = 1; i <= m; i++){
        res *= filter * A[i][i];
    }
    cout << res;
        

}