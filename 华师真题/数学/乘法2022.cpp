#include <bits/stdc++.h>
using namespace std;

// 统计乘积 >= mid 的元素个数
long long countGreater(const vector<int>& A, const vector<int>& B, long long mid) {
    long long cnt = 0;
    int m = B.size();
    for (int x : A) {
        if (x == 0) {
            // 0 * B[j] >= mid 只有当 mid <= 0 时成立
            if (mid <= 0) cnt += m;
        } else if (x > 0) {
            // B[j] >= ceil(mid/x)，找第一个满足的位置
            long long target = (mid + x - 1) / x;  // ceil(mid/x)
            int pos = lower_bound(B.begin(), B.end(), target) - B.begin();
            cnt += m - pos;
        } else {
            // x < 0, B[j] <= floor(mid/x)，找最后一个满足的位置
            long long target = mid / x;  // floor(mid/x)
            int pos = upper_bound(B.begin(), B.end(), target) - B.begin();
            cnt += pos;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;
    K = n * m - K + 1;  // 第K大 -> 第(n*m-K+1)小

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long left = -1e12, right = 1e12, ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (countGreater(A, B, mid) >= K) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}