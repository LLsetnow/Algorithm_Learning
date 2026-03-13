#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e9 + 5;
const int INF = 1e9 + 5;

int main() {
    // 开启快速 I/O，应对 10^5 次查询
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    if (!(cin >> n >> m)) return 0;

    int q;
    cin >> q;

    while (q--) {
        ll x, y;
        cin >> x >> y;

        // 1. 计算当前点所在的层数 k (从 0 开始)
        // 这里的变量全是 long long，所以用 {} 列表不会报错
        ll k = min({x - 1, n - x, y - 1, m - y});

        // 2. 计算外层所有元素总数 (基础值)
        ll base = n * m - (n - 2 * k) * (m - 2 * k);

        // 3. 计算当前层的尺寸以及点的相对坐标
        ll N_prime = n - 2 * k;
        ll M_prime = m - 2 * k;
        ll r = x - k;
        ll c = y - k;

        ll ans = 0;

        // 4. 分四条边分类讨论
        if (r == 1) {
            // 在当前圈的上边
            ans = base + c;
        } else if (c == M_prime) {
            // 在当前圈的右边
            ans = base + M_prime + r - 1;
        } else if (r == N_prime) {
            // 在当前圈的下边
            ans = base + M_prime + N_prime - 1 + (M_prime - c);
        } else {
            // 在当前圈的左边
            ans = base + M_prime + N_prime - 1 + M_prime - 1 + (N_prime - r);
        }

        cout << ans << "\n"; // 避免使用 endl，提高输出速度
    }

    return 0;
}
