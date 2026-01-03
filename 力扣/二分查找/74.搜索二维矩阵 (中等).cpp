/*
思路：
    将二维数组视为一维数组进行二分查找
    matrix[i][j] = matrix[i * n + j]

*/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();      // 行数
            int n = matrix[0].size();   // 列数
            int i = 0;
            int j = m * n - 1;
            int mid = 0;
            while(i <= j){
                mid = (i + j) / 2;
                if(matrix[mid / n][mid % n] == target) return true;
                if(matrix[mid / n][mid % n] < target) i = mid + 1;
                if(matrix[mid / n][mid % n] > target) j = mid - 1;
            }
            return false;
        }
    };

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution s;
    bool res = s.searchMatrix(matrix, target);
    cout << res << endl;


}