#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector <int> ans;
            if(matrix.empty()) return ans; //若数组为空，直接返回答案
            //赋值上下左右边界
            int u = 0; 
            int d = matrix.size() - 1;
            int l = 0;
            int r = matrix[0].size() - 1;
            while(true)
            {
                //向右移动至边界
                for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); 
                //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
                if(++ u > d) break; 
                //向下移动至边界
                for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); 
                //重新设定右边界
                if(-- r < l) break; 
                for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); 
                //重新设定下边界
                if(-- d < u) break; 
                for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); 
                //重新设定左边界
                if(++ l > r) break; 
            }
            return ans;
        }
    };

int main(){
    system("chcp 65001>nul");
    system("clear");
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> res = s.spiralOrder(matrix);
    for(int x : res){
        cout << x << ",";
    }
}