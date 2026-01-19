/*
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

    值 0 代表空单元格；
    值 1 代表新鲜橘子；
    值 2 代表腐烂的橘子。

每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    private:
        // 使用BFS模拟腐烂传播过程
        int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& freshCount){
            int time = 0;
            int row = grid.size();
            int col = grid[0].size();
            int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            while(!q.empty()){
                int size = q.size();
                bool rotted = false;

                for(int i = 0; i < size; i++){
                    auto curr = q.front();
                    q.pop();

                    for(auto& dir : directions){
                        int newRow = curr.first + dir[0];
                        int newCol = curr.second + dir[1];

                        if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 1){
                            grid[newRow][newCol] = 2;
                            freshCount--;
                            q.push({newRow, newCol});
                            rotted = true;
                        }
                    }
                }

                if(rotted) time++;
            }

            return time;
        }

    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int freshCount = 0;  // 统计新鲜橘子数量
            int row = grid.size();
            int col = grid[0].size();
            queue<pair<int, int>> q;  // 存储所有初始腐烂橘子的位置

            // 第一次遍历：统计新鲜橘子数量，并将所有腐烂橘子入队
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(grid[i][j] == 1){
                        freshCount++;
                    }
                    else if(grid[i][j] == 2){
                        q.push({i, j});
                    }
                }
            }

            int time = bfs(grid, q, freshCount);

            // 如果还有新鲜橘子，返回-1；否则返回所需时间
            if(freshCount == 0)
                return time;
            else
                return -1;
        }
    };

int main(){
    Solution solution;
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << solution.orangesRotting(grid) << endl;
}