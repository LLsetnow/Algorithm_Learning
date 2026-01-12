/* 
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中相邻单元格是那些水平相邻或垂直相邻的单元格（而不是对角线相邻）。
同一个单元格内的字母不允许被重复使用。
示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
*/


 



#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;
class Solution {
    enum{
        up,
        down,
        left,
        right
    };
    private:
        void back_position(int &x, int &y, int direction){
            switch(direction){
                case up:
                    x++;
                    break;
                case down:
                    x--;
                    break;
                case left:
                    y++;
                    break;
                case right:
                    y--;
                    break;
            }
        }

    public:
        bool exist(vector<vector<char>>& board, string word) {
            
            bool result = false;
            int rows = board.size();
            int cols = board[0].size();
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(board[i][j] == word[0]){
                        vector<char> path;
                        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                        int x = i;
                        int y = j;
                        path.push_back(board[i][j]);
                        visited[i][j] = true;

                        function<void()> backtrack = [&](){
                            // 终止条件
                            if(path.size() == word.size()){
                                result = true;
                                return;
                            }
                            // 剪枝：如果已经找到结果，直接返回
                            if(result) return;

                            // 向上
                            if(x > 0 && !visited[x - 1][y] && board[x - 1][y] == word[path.size()]){
                                path.push_back(board[x - 1][y]);
                                visited[x - 1][y] = true;
                                x--;
                                backtrack();
                                x++;
                                visited[x][y] = false;
                                path.pop_back();
                            }
                            // 向下
                            if(x < rows - 1 && !visited[x + 1][y] && board[x + 1][y] == word[path.size()]){
                                path.push_back(board[x + 1][y]);
                                visited[x + 1][y] = true;
                                x++;
                                backtrack();
                                x--;
                                visited[x][y] = false;
                                path.pop_back();
                            }
                            // 向左
                            if(y > 0 && !visited[x][y - 1] && board[x][y - 1] == word[path.size()]){
                                path.push_back(board[x][y - 1]);
                                visited[x][y - 1] = true;
                                y--;
                                backtrack();
                                y++;
                                visited[x][y] = false;
                                path.pop_back();
                            }
                            // 向右
                            if(y < cols - 1 && !visited[x][y + 1] && board[x][y + 1] == word[path.size()]){
                                path.push_back(board[x][y + 1]);
                                visited[x][y + 1] = true;
                                y++;
                                backtrack();
                                y--;
                                visited[x][y] = false;
                                path.pop_back();
                            }
                        };
                        
                        backtrack();

                        // 如果找到结果，立即返回
                        if(result) return true;
                    }
                }
            }
            return result;
        }
    };