#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    i64 n,s;
    cin >> n >> s;
    vector<i64> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    i64 sum = 0;
    if(A[n / 2] > s){
        for(int i = n / 2; i >= 0; i--){
            if(A[i] <= s) break;
            sum += abs(A[i] - s);
        }
    }
    else if(A[n / 2] < s){
        for(int i = n / 2; i < n; i++){
            if(A[i] >= s) break;
            sum += abs(A[i] - s);
        }
    }

    cout << sum;
}