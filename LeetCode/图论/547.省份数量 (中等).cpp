/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    private:
        // 传播第province[i]相关的所有城市
        void bfs(vector<vector<int>>& isConnected, vector<int>& province, int i){
            int n = isConnected.size();
            queue<int> q;
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && province[j] == 0){
                    province[j] = province[i];
                    q.push(j);
                }
            }
            // 队头 < 队尾
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j = 0; j < n; j++){
                    if(isConnected[cur][j] == 1 && province[j] == 0){
                        province[j] = province[cur];
                        q.push(j);
                    }
                }
            }
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int count = 0;
            int n = isConnected.size();
            vector<int> province(n, 0);
            for(int i = 0; i < n; i++){
                if(province[i] == 0){
                    count++;
                    province[i] = count;
                    bfs(isConnected, province, i);
                }
            }
            return count;
        }
    };

int main(){
    Solution s;
    vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    cout << s.findCircleNum(isConnected) << endl;
}