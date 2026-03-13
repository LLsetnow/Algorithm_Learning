/*
给定两个正整数a和b，求在[a，b]中的所有整数中，每个数字（0~9）各出现了多少次。

算法思想：数位DP（按位统计）
- 不遍历每个数，而是按位统计每个数字在每一位上出现的次数
- 时间复杂度：O(log n * 10)，可以处理 n <= 10^18
- 利用前缀和思想：count(a, b) = count(0, b) - count(0, a-1)

按位统计原理（以数字d为例）：
对于数字的每一位，将该位固定为d，统计合法的数字个数
- high：当前位左侧的高位部分
- curr：当前位数字
- low：当前位右侧的低位部分
- power：当前位的位权（1, 10, 100, ...）
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 统计[0, x]中数字d出现的次数
i64 count(i64 x, int d) {
    if (x < 0) return 0;           // 负数返回0
    if (x == 0) return d == 0 ? 1 : 0;  // 0中只有数字0出现1次

    i64 res = 0;
    i64 power = 1;  // 当前位的位权

    // 按位遍历：个位、十位、百位...
    while (power <= x) {
        i64 high = x / (power * 10);    // 当前位左侧的数字
        i64 curr = (x / power) % 10;    // 当前位的数字
        i64 low = x % power;            // 当前位右侧的数字

        if (d > 0) {
            // 数字1-9的处理
            if (curr < d) {
                // 当前位比d小，只能取0到curr-1，贡献：high个完整的power区间
                res += high * power;
            } else if (curr == d) {
                // 当前位等于d，贡献：high个完整区间 + low+1个（当前位固定为d，低位自由取）
                res += high * power + low + 1;
            } else {
                // 当前位比d大，贡献：(high+1)个完整区间
                res += (high + 1) * power;
            }
        } else {
            // 数字0需要特殊处理（不能有前导0）
            if (high > 0) {  // 高位存在才能放0
                if (curr == 0) {
                    // 当前位是0，贡献：(high-1)个区间 + low+1
                    res += (high - 1) * power + low + 1;
                } else {
                    // 当前位不是0，贡献：high个区间
                    res += high * power;
                }
            }
            // 特殊情况：当处理个位且x=0时，已在前面处理
            // 当x>0时，个位的0在high>0的情况中已经正确统计
        }

        power *= 10;  // 移动到下一位
    }

    if (d == 0 && x > 0) {
        res += 1;  // 数字0本身有一个0
    }

    return res;
}

int main() {
    i64 a, b;
    cin >> a >> b;  // 输入区间[a, b]

    vector<i64> cnt(10, 0);

    // 利用前缀和计算每个数字在[a, b]中出现的次数
    for (int d = 0; d < 10; d++) {
        cnt[d] = count(b, d) - count(a - 1, d);
    }

    // 输出结果：0-9每个数字出现的次数
    for (int d = 0; d < 9; d++)
        cout << cnt[d] << " ";
    cout << cnt[9] << endl;

    return 0;
}
