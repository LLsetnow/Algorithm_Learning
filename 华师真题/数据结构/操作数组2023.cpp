// 常规解法
#include<bits/stdc++.h>
using namespace std;
const int MAXNUMBER = 30;
int cnt[MAXNUMBER + 1];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    cnt[1] = n;
    vector<int> vec(n + 1, 1);

    while(m--){
        char ins;
        cin >> ins;
        // 修改
        if(ins == 'C'){
            int l, r, x;
            cin >> l >> r >> x;
            for(int i = l; i <= r; i++){
                cnt[vec[i]]--;
                cnt[x]++;
                vec[i] = x;
            }
        }   
        // 查询
        else{
            int l, r;
            cin >> l >> r;
            int ans = 0;
            vector<int> cnt2(MAXNUMBER, 0);
            for(int i = l; i <= r; i++){
                cnt2[vec[i]]++;
                ans = max(ans, cnt2[vec[i]]);
            }
            cout << ans << endl;
        }
    }
    return 0;

}