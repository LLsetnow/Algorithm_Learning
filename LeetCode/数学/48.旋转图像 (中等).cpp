/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。
请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，
这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

提示：

    n == matrix.length == matrix[i].length
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000


思路：
    n = 3 中点 i = 1
    [0,0] -> [0,2]
    [0,1] -> [1,2]
    [0,2] -> [2,2]

    [1,0] -> [0,1]

    n = 4 中点 i = 2
    [1,1] -> [1,2]

    原行 + 目标列 = n - 1
    原列 = 目标行

    以上两个过程可以简化为
    [原行, 原列] ->（转置） [原列, 原行] ->（按行翻转） [原列，n - 1 - 原行]


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int row = 0;
            int col = 0;
            for(int i = n; i > 0; i -= 2){
                for(int j = 0; j < i - 1; j++){
                    col = row + j;
                    int temp;
                    int newValue;
                    for(int k = 0; k < 4; k++){
                        int newRow = col;
                        int newCol = n - 1 - row;
                        if(k == 0){
                            newValue = matrix[newRow][newCol];
                            matrix[newRow][newCol] = matrix[row][col];
                        }
                        else{
                            temp = newValue;
                            newValue = matrix[newRow][newCol];
                            matrix[newRow][newCol] = temp;
                        }
                        cout << "[" << row << "][" << col << "] -> [" << newRow << "][" << newCol << "]" << endl;
                        row = newRow;
                        col = newCol;
                    }
                }
                row++;
            }      
        }
        // 从数学原理优化
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            // 矩阵转置
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            // 矩阵按行翻转
            for(int i = 0; i < n; i++){
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }

    };


int main(){

    Solution s;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(matrix);
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}