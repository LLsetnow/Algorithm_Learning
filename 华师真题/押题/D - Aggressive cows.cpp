/*
n 个位置
其中选c个位置，淘汰n-c个位置
让整个数组的相邻最小距离最大

n-1个区间段
可以选择其中 两个区间进行合并，可以合并 n-c次
让区间段的最小值 最大

思路：二分答案 + 贪心

二分答案 mid = 最小间距
check(mid): 判断是否能在最多合并 x=n-c 次的前提下，
             让所有保留的间距都 >= mid

贪心check逻辑:
    遍历所有间距，统计需要合并多少个小的间距
    合并次数 <= x 说明可行，需要增大 mid
    否则不可行，需要减小 mid


输入输出样例
输入样例#:

5 3
1
2
8
4
9

输出样例#:

3


*/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int XN = 1e9 + 5;
const int N = 1e5 + 5;
int pos[N];   // 位置 [1-based]

// 检查能否让最小间距 >= target
// 返回：是否能保留至少 c-1 个间距都 >= target
bool check(int n, int merge_limit, int target) {
    int cnt = 0;      // 已保留的间距数量（都 >= target）
    int cur_sum = 0;  // 当前合并区间的总长度

    for(int i = 1; i < n; i++) {
        int gap = pos[i] - pos[i-1];
        cur_sum += gap;

        if(cur_sum >= target) {
            cnt++;      // 成功保留一个间距
            cur_sum = 0;  // 重新开始合并
        }
    }

    // 需要保留 c-1 个间距
    return cnt >= (n - merge_limit - 1);
}

int main(){
    int n, c;
    while(cin >> n >> c){
        for(int i = 0; i < n; i++) {
            cin >> pos[i];
        }
        sort(pos, pos + n);
    
        int merge_limit = n - c;  // 最多可以合并的次数
    
        // 对答案二分：最小间距
        int l = 1, r = pos[n-1] - pos[0], ans = 1;
    
        while(l <= r) {
            int mid = l + (r - l) / 2;
            // cout << "[" << l << ", " << r << "] mid = " << mid << endl;
            if(check(n, merge_limit, mid)) {
                ans = mid;  // 取到等号
                l = mid + 1;  // 可行，尝试更大
            } else {
                r = mid - 1;  // 不可行，尝试更小
            }
        }
    
        cout << ans << endl;
    }
    return 0;
}

