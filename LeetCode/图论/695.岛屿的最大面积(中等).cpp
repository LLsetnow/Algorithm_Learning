/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    private:
        int dfs(vector<vector<int>>& grid, int i, int j, int r, int l) {
            if(i < 0 || i >= r || j < 0 || j >= l || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            return 1 + dfs(grid, i + 1, j, r, l) +
                       dfs(grid, i - 1, j, r, l) +
                       dfs(grid, i, j + 1, r, l) +
                       dfs(grid, i, j - 1, r, l);
        }

    public:
        // 版本1 使用lambda函数
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int r = grid.size();
            int l = grid[0].size();
            //int count = 0;
            int max_size = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < l; j++){
                    if(grid[i][j] == 1){
                        int size = 0;
                        // 需要记录的数据直接调用外部变量
                        // 不要改变的数据，采用递归输入的方式
                        // 每次循环都会创建一次lambda函数 导致耗时增加
                        function<void(int, int)> dfs = [&](int i, int j){
                            if(i < 0 || i >= r || j < 0 || j >= l || grid[i][j] == 0) return;
                            size++;
                            grid[i][j] = 0;
                            dfs(i + 1, j);
                            dfs(i - 1, j);
                            dfs(i, j + 1);
                            dfs(i, j - 1);
                        };
                        dfs(i, j);
                        max_size = max(max_size, size);                            
                        // count++;
                    }
                }
            }
            return max_size;
        }
        // 优化版本2：使用递归函数
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int r = grid.size();
            int l = grid[0].size();
            int max_size = 0;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < l; j++){
                    if(grid[i][j] == 1){
                        max_size = max(max_size, dfs(grid, i, j, r, l));
                    }
                }
            }
            return max_size;
        }

        // 优化版本3：使用迭代+栈，避免递归栈溢出
        int maxAreaOfIsland3(vector<vector<int>>& grid) {
            int r = grid.size();
            int l = grid[0].size();
            int max_size = 0;
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for(int i = 0; i < r; i++){
                for(int j = 0; j < l; j++){
                    if(grid[i][j] == 1){
                        int size = 0;
                        stack<pair<int, int>> stk;
                        stk.push({i, j});
                        grid[i][j] = 0;

                        while(!stk.empty()){
                            auto [x, y] = stk.top();
                            stk.pop();
                            size++;

                            for(auto& [dx, dy] : directions){
                                int nx = x + dx, ny = y + dy;
                                if(nx >= 0 && nx < r && ny >= 0 && ny < l && grid[nx][ny] == 1){
                                    grid[nx][ny] = 0;
                                    stk.push({nx, ny});
                                }
                            }
                        }
                        max_size = max(max_size, size);
                    }
                }
            }
            return max_size;
        }
    };
int main(){
    Solution solution;
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    cout << "maxAreaOfIsland: " << solution.maxAreaOfIsland(grid) << endl;

    vector<vector<int>> grid2 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    cout << "maxAreaOfIsland2: " << solution.maxAreaOfIsland2(grid2) << endl;
    return 0;
}
