#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            if(source == destination) return true;

            // 构建邻接表
            vector<vector<int>> adj(n);
            for(auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            vector<int> visited(n, 0);
            queue<int> q;
            q.push(source);
            visited[source] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int neighbor : adj[cur]){
                    if(neighbor == destination) return true;
                    if(visited[neighbor] == 0){
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            return false;
        }
    };

int main(){
    Solution sol;
    system("chcp 65001>nul");
    vector<vector<int>> edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    cout << sol.validPath(10, edges, 5, 9) << endl;
}