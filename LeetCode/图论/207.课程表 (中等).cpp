/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

    例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。

请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

- 思路（基于邻接表的拓扑排序）
	    1. 构建邻接表：adj[i] 存储课程 i 指向的所有课程（即哪些课需要先修课程 i）
	    2. 统计所有点的入度：indegree[i] 表示课程 i 有多少个先修课
	    3. 将所有入度为0的点加入队列：这些课没有先修要求，可以直接完成
	    4. 每次从队列取出一个点，就 count++（表示完成这门课）
	    5. 遍历该点在邻接表中指向的所有点，将这些点的入度-1（因为先修课已完成）
	    6. 如果某个点的入度变为0，加入队列（意味着它的所有先修课都已完成）
	    7. 重复步骤4-6，直到队列为空
	    8. 最终判断 count 是否等于 numCourses
*/

#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            // 邻接表：存储每个课程指向的课程（即哪些课需要先修当前课程）
            vector<vector<int>> adj(numCourses);
            // 入度数组：统计每个课程的先修课数量
            vector<int> indegree(numCourses, 0);
            
            // 构建邻接表和入度数组
            for(auto &prerequisite : prerequisites){
                int course = prerequisite[0];
                int prerequisite_course = prerequisite[1];
                // adj[prerequisite_course] 记录 结点prerequisite_course的所有出度结点
                adj[prerequisite_course].push_back(course);
                // indegree[course] 记录 结点course的入度数量
                indegree[course]++;
            }
            
            // 队列：存储当前可以完成的课程（入度为0的课程）
            queue<int> zeroNode;
            for(int i = 0; i < numCourses; i++){
                if(indegree[i] == 0){
                    zeroNode.push(i);
                }
            }
            
            // 已完成课程数量
            int count = 0;
            
            // 拓扑排序
            while(!zeroNode.empty()){
                int node = zeroNode.front();
                zeroNode.pop();
                count++;
                
                // 遍历该课程指向的所有课程，将它们的入度-1
                for(int neighbor : adj[node]){
                    indegree[neighbor]--;
                    // 如果入度变为0，加入队列
                    if(indegree[neighbor] == 0){
                        zeroNode.push(neighbor);
                    }
                }
            }
            
            // 所有课程已完成
            return count == numCourses;
        }
    };
int main(){
    system("chcp 65001>nul");
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool result = solution.canFinish(numCourses, prerequisites);
    cout << (result ? "true" : "false") << endl;
    return 0;
}