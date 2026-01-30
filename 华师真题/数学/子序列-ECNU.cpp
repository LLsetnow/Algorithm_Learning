#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
// 双指针法 100% 正确
int main(){
    i64 n, S, b;
    int mod = 1e9 + 7;
    cin >> n >> S;  
    vector<i64> A(n);
    cin >> A[0] >> b;  

    for(int i = 1; i < n; i++){
        A[i] = (b * A[i - 1]) % mod;
    }

    // 双指针找所有符合条件的子序列 记录长度最小的子序列
    i64 minLegth = INT_MAX;
    i64 i = 0;
    i64 j = 0;
    i64 sum = 0;
    while(j < n){
        sum += A[j];
        while(sum >= S && i <= j){
            minLegth = min(minLegth, 1ll * j - i + 1);
            sum -= A[i];
            i++;
        }
        j++;
    }
    cout << (minLegth == INT_MAX ? -1 : minLegth);  // 如果没有解输出-1
}

// 前缀和 80% 正确
int main(){
    int n, S, b;
    int mod = 1e9 + 7;
    cin >> n >> S;  
    vector<long long> A(n+1, 0);
    vector<long long> B(n+1, 0);
    cin >> A[1] >> b;  
    B[1] = A[1];

    // 计算前缀和
    for(int i = 2; i < n + 1; i++){
        A[i] = (b * A[i - 1]) % mod;
        B[i] = (A[i] + B[i-1]) % mod;
    }

    int minLegth = INT32_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n + 1; j++){
            if(B[j] - B[i] >= S){
                minLegth = min(minLegth, j - i);
            }
        }
    }

    if(minLegth == INT32_MAX)
        cout << -1;
    else    
        cout << minLegth;
}