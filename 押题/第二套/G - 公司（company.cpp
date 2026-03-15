#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
int salory[MAXN];
int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++) cin >> salory[i];
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(salory[b]);
    }
    int cnt = 0;
    // 离职判读
    for(int i = 1; i <= n; i++){
        if(mp.find(i) != mp.end()){
            int sum = 0;
            for(int j = 0; j < mp[i].size(); j++){
                sum += mp[i][j];
            }
            double ave = sum / mp[i].size();
            if(salory[i] < ave) cnt++;
        }
    }
    cout << cnt;

}