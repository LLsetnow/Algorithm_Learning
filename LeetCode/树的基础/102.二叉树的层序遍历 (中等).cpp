/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：

输入：root = [1]
输出：[[1]]

示例 3：

输入：root = []
输出：[]

思路：
    广度优先搜索，使用队列
    我们可以想到最朴素的方法是用一个二元组 (node, level) 来表示状态，
    它表示某个节点和它所在的层数，每个新进队列的节点的 level 值都是父亲节点的 level 值加一。
    最后根据每个点的 level 对点进行分类，
    分类的时候我们可以利用哈希表，维护一个以 level 为键，对应节点值组成的数组为值，
    广度优先搜索结束以后按键 level 从小到大取出所有值，组成答案返回即可。

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*> q;
            if(root == nullptr) return {};
            q.push(root);
            vector<vector<int>> res;
            // 开始层次遍历(队列不为空)
            while(!q.empty()){
                int size = q.size();
                // 每一层的节点值
                vector<int> tmp;
                // 每一轮只访问一层
                for(int i = 0; i < size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    tmp.push_back(node->val);
                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                res.push_back(tmp);
            }
            return res;
        }
    };


int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);
    for(auto& vec : result){
        for(auto& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
}