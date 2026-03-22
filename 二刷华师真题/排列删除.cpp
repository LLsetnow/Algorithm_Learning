#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int p[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    int q; cin >> q;
    while(q--){
        // 左边 比 右边大 右边元素可以删掉
        int x, y;
        cin >> x >> y;
        // 要删 p[x] 不能删p[y]

        if(x < y){
            printf("Yes\n");
            continue;
        }
        int maxNum = -1;
        for(int i = y; i < x; i++){
            maxNum = max(maxNum, p[i]);
            if(maxNum > p[x]) break;
        }
        if(maxNum > p[x]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }


    }
}