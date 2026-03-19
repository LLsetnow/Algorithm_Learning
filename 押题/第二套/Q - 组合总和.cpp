#include <bits/stdc++.h>
using namespace std;

const int MAXN = 33;

int a[MAXN];

vector<int> path;
vector<vector<int>> paths;

// n数字个数a[1-n] start枚举起点 cur当前总和 target目标和
void backTrack(int n, int start, int cur, int target){
    // 成功回溯
    if(cur == target){
        paths.push_back(path);
        return;
    }

    // 失败剪枝：如果当前值已经超过目标，或者start越界
    if(start > n || cur + a[start] > target){
        return;
    }

    // 枚举所有可能
    for(int i = start; i <= n; i++){
        // 剪枝：如果加上当前值超过目标，后续更大的值也会超过（因为排序了）
        if(cur + a[i] > target) break;

        // 选择
        path.push_back(a[i]);
        // 递归
        backTrack(n, i, cur + a[i], target);
        // 撤销选择
        path.pop_back();
    }
}
int main(){

    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n); //升序排序

    // 回溯找所可能
    backTrack(n, 1, 0, t);
    for(auto &p : paths){
        for(auto &x : p){
            cout << x << " ";
        }
        cout << endl;
    }
}