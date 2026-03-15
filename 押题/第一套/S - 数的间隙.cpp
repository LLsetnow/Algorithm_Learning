#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e9 + 5;
const int INF = 1e9 + 5;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int cnt = 1;
    int last = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - last > d){
            cnt++;
            last = a[i];
        }
    }
    cout << cnt;
}