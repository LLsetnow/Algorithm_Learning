/*
在一个由 0、1 元素构成矩阵中，统计至少含有 k个 1 的矩形的个数（矩形边界平行于矩阵边界）。
注意：单个元素也算是一个矩形。
输入输出格式
输入描述:
第一行，有四个空格分隔的整数，r,c,n,k ( 1≤r,c,n≤500,1≤k≤n ) 分别表示矩阵的行数，列数，矩阵中 1 的个数，和题意中给出的 k。
接下来 n 行，每行两个空格分隔的整数 x 和 y，表示每个 1 所在的位置 ( 1≤xi≤r,1≤yi≤c)
输出描述:
输出1行1个数字，表示矩形的个数。


输入输出样例
输入样例#:
5 5 4 2
5 4
5 5
1 5
2 4

输出样例#:
41


思路：
    构造一个二维前缀和,用于快速计算一个区域内的1的个数
    使用滑动窗口优化，时间复杂度 O(r²c)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, n, k;
    cin >> r >> c >> n >> k;
    int a[501][501] = {0};
    int s[501][501] = {0};

    // 读取坐标并填充矩阵
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }

    // 构建二维前缀和数组
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }

    long long sum = 0;

    for(int top = 1; top <= r; top++){
        for(int bottom = top; bottom <= r; bottom++){
            
            int col_sum[501] = {0};
            // 计算当前行范围内每列的总和
            for(int j = 0; j < c; j++){
                int col = j + 1;
                col_sum[j] = s[bottom][col] - s[top - 1][col]
                           - s[bottom][col - 1] + s[top - 1][col - 1];
            }

            // 滑动窗口统计列方向满足条件的子矩阵数
            int left = 0, current_sum = 0, cnt = 0;
            for(int right = 0; right < c; right++){
                current_sum += col_sum[right];
                // 当和≥k时，移动左指针并累加所有可能的左边界组合
                while(current_sum >= k){
                    cnt += (c - right);  
                    current_sum -= col_sum[left];
                    left++;
                }
            }
            sum += cnt;
        }
    }
    cout << sum << endl;
    return 0;
}
