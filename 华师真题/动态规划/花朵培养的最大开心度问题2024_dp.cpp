#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    i64 n, newFlowers, target, full, partial;
    cin >> n;

    vector<i64> flowers(n);
    for(auto &x : flowers) cin >> x;
    cin >> newFlowers >> target >> full >> partial;

    // 排序：从小到大
    sort(flowers.begin(), flowers.end());

    // 计算前缀和：prefix[i] = flowers[0] + flowers[1] + ... + flowers[i-1]
    vector<i64> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + flowers[i];
    }

    // 预计算：将前i株花都培育到target需要的花朵数
    vector<i64> needToTarget(n + 1, 0);
    for(int i = 1; i <= n; i++){
        // 第i株花（下标i-1）从flowers[i-1]培育到target
        if(flowers[i - 1] < target){
            needToTarget[i] = needToTarget[i - 1] + (target - flowers[i - 1]);
        } else {
            needToTarget[i] = needToTarget[i - 1];
        }
    }

    i64 maxScore = 0;

    // 枚举完善花组数量k：从最多到最少
    // 完善花组：后k株花（flowers[n-k], flowers[n-k+1], ..., flowers[n-1]）
    // 不完善花组：前(n-k)株花
    for(i64 k = 0; k <= n; k++){
        // 让后k株花完善需要的花朵 = 总需要 - 前(n-k)株需要的
        i64 cost = needToTarget[n] - needToTarget[n - k];

        if(cost > newFlowers) continue;  // 花朵不够，跳过

        i64 remain = newFlowers - cost;  // 剩余花朵用于培育前(n-k)株花

        // 求不完善花组的最大最小值
        // 用二分答案：最大能达到的最小值mid
        i64 left = 1, right = target - 1, maxMin = 0;

        if(n - k > 0){
            while(left <= right){
                i64 mid = (left + right) / 2;

                // 找到第一个 >= mid 的位置
                i64 idx = lower_bound(flowers.begin(), flowers.begin() + (n - k), mid) - flowers.begin();

                if(idx == 0){
                    // 所有花都 < mid，需要全部培育到mid
                    i64 need = mid * (n - k) - prefix[n - k];
                    if(need <= remain){
                        maxMin = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    // 前idx株花需要培育到mid
                    i64 need = mid * idx - prefix[idx];
                    if(need <= remain){
                        maxMin = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        // 计算总开心度
        i64 score = k * full + maxMin * partial;
        maxScore = max(maxScore, score);
    }

    cout << maxScore;
    return 0;
}