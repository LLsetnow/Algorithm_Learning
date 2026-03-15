/*
现在的问题是，数组a中某些数据损坏了，
我们只知道数组中的一部分数据和数组的大小N，
我们想知道查找整数X最大的可能的查找次数，
我们假设数组中每个数都不相同，
且X一定出现在原数组中,a在被损坏前的是已经排好序的。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e9 + 5;
const int INF = 1e9 + 5;

// 返回查找次数
int binarySearch(int a[],int L, int R, int x)
{
    int cnt=0;
    int mid;
    while(L <= R)
    {
        cnt++;
        mid = L + (R - L) / 2;
        if(a[mid] == -1){
            return cnt + max(binarySearch(a, L, mid - 1, x), binarySearch(a, mid + 1, R, x));
        }
        if(a[mid] == x) return cnt;
        if(x < a[mid])  R = mid - 1;
        if(x > a[mid])  L = mid + 1;
    }
    return cnt;//查找失败

}

int main(){
    int n, x;
    while(cin >> n){
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        cin >> x;
        cout << "cnt : "<< binarySearch(a, 0, n-1, x) << "\n";

    }
}