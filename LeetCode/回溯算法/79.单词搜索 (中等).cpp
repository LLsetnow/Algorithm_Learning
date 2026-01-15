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
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int h = board.size(), w = board[0].size();
            vector<vector<int>> visited(h, vector<int>(w));
            
            function<bool(int, int, int)> check = [&](int i, int j, int k) {
                if (board[i][j] != word[k]) {
                    return false;
                } else if (k == word.length() - 1) {
                    return true;
                }
                visited[i][j] = true;
                vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                bool result = false;
                for (const auto& dir: directions) {
                    int newi = i + dir.first, newj = j + dir.second;
                    if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                        if (!visited[newi][newj]) {
                            bool flag = check(newi, newj, k + 1);
                            if (flag) {
                                result = true;
                                break;
                            }
                        }
                    }
                }
                visited[i][j] = false;
                return result;
            };
            
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    bool flag = check(i, j, 0);
                    if (flag) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
    