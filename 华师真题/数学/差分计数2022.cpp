#include <bits/stdc++.h>
using namespace std;

// 哈希表查询
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> vec(n);
    unordered_map<int , int> cnt;
    // O(n)
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        cnt[vec[i]]++;
    }

    long long ans = 0;
    // O(n)
    for(auto &p : cnt){
        int num = p.first;      // 数字大小
        int c = p.second;       // 数字个数
        int target = num + x;
        if(cnt.count(target)){
            ans += (long long)c * cnt[target];
        }
    }

    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 2e6;
const int N = INF * 2 + 1;
int buck[N];

// 桶计数
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    memset(buck, 0, sizeof(buck));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        buck[x + INF]++;
    }
    long long ans = 0;

    for(int i = 0; i < N; i++) {
        if(buck[i] == 0) continue;
        // 映射原值
        int val = i - INF;  
        // 目标数大小
        int target = val + x;

        int j = target + INF;
        if(j >= 0 && j < N && buck[j] > 0) {
            ans += (long long)buck[i] * buck[j];
        }
    }

    cout << ans << endl;

}