#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXM = 15;
const int MAXN = 1e5 + 5;

int a[MAXN];
int CLIP(int s){
    if(s < 1) return 1;
    if(s > 7) return 7;
    return s;
}

// 8min Ac
int main(){
    int n; cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int score = 0;
    for(int i = 1; i <= n; i++){
        if(sum % a[i] == 0) score = max(score, a[i]);
    }
    int A = CLIP(score);

    int m; cin >> m;
    ll x = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            int temp;
            cin >> temp;
            if(i == j) x *= temp * A;
        }
    }

    cout << x;

}