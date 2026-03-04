#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int, int>> val(n);
    
    // c++ 17
    for(auto &[a, b] : val){
        cin >> a >> b;
    }
    // c++ 14
    for(auto &x : val){
        cin >> x.first >> x.second;
    }
    int empty = n - m;
    vector<vector<int>> dp(n, vector<int> (empty + 1, -1));
    function<int(int, int)> dfs = [&](int i, int j){
        // 临界条件
        if(i < 0) return 0;
        int &res = dp[i][j];
        // 该情况计算过了
        if(res != -1) return res;
        
        res = max(dfs(i - 1, j) + val[i].first, dfs(i - 1, j - 1) + val[i].second);
        return res;
    };

    cout << dfs(n - 1, empty);
}