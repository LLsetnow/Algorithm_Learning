#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

// 统计矩阵中(A,B元素乘积)大于mid的个数
long long countGreater(const vector<int>& A, const vector<int>& B, long long mid) {
    long long cnt = 0;
    int m = B.size();
    for (int x : A) {
        if (x == 0) {
            if (mid <= 0) cnt += m;
        } else if (x > 0) {
            long long target = (mid + x - 1LL) / x;
            long long pos = lower_bound(B.begin(), B.end(), target) - B.begin();
            cnt += m - pos;
        } else {
            long long target = mid / x;
            cnt += upper_bound(B.begin(), B.end(), target) - B.begin();
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K;
    cin >> n >> m >> K;
    K = n * 1LL * m - K + 1;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long left = -INF, right = INF, ans = right;
    // 直接对答案可能区间进行二分查找
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (countGreater(A, B, mid) <= K) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

/* 测试案例
1. 正数测试
输入:
3 3 3
2 3 4
4 5 6
输出: 20
解释: 乘积矩阵为 [8,10,12,12,15,18,16,20,24]，第3大是20

2. 混合正负数
输入:
3 3 2
-2 0 3
-3 4 5
输出: 12
解释: 乘积矩阵为 [6,-8,-10,-4,0,0,12,15,15]，第2大是15

3. 单个元素
输入:
1 1 1
5
7
输出: 35

4. 全负数
输入:
2 2 3
-5 -3
-4 -2
输出: 10
解释: 乘积矩阵为 [20,10,12,6]，第3大是10

5. 含零
输入:
3 2 4
-2 0 3
-1 2
输出: 0
解释: 乘积矩阵为 [2,-4,0,0,-3,6]，第4大是0

6. 大数值
输入:
2 2 1
100000 200000
300000 400000
输出: 80000000000

7. 极端情况：全相同
输入:
2 3 6
2 2
3 3 3
输出: 6
解释: 所有乘积都是6，第6大是6

8. K=n*m（找最小）
输入:
3 3 9
1 2 3
4 5 6
输出: 4
解释: 乘积最小是4
*/