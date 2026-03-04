#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> vec(N);
    // 计算前缀和
    vector<int> s(N + 1, 0);
    for(int i = 1; i <= N; i++){
        int x;
        cin >> x;
        vec[i - 1] = x;
        s[i] = s[i - 1] + vec[i - 1]; 
    }

    int Q;
    cin >> Q;

    // 时间复杂度O(QN)
    // while(Q--){
    //     int l, r;
    //     cin >> l >> r;
    //     long long sum = 0;
    //     for(int i = l; i <= r; i++){
    //         sum += vec[i - 1];
    //     }
    //     int ave = round(sum /= (r - l + 1));
    //     sum = 0;
    //     for(int i = l; i <= r; i++){
    //         sum += abs(vec[i - 1] - ave);
    //     }
    //     printf("%d\n", sum);
    
    // }

    // 改进
    while(Q--){
        int l, r;
        cin >> l >> r;
        int ave = round((s[r] - s[l - 1]) * 1.0 / (r - l + 1)) ;
        long long sum = 0;
        for(int i = 1; i <= r; i++){
            sum += abs(vec[i - 1] - ave);
        }
        printf("%d\n", sum);
    }

    return 0;

}