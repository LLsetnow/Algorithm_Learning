/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/
#include<iostream>
#include<vector>
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
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr) return nullptr;
            invert(root);
            return root;
        }

        void invert(TreeNode* root){
            if(root == nullptr) return;
            // 交换左右子节点
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invert(root->left);
            invert(root->right);
        }
        // 中序遍历
        void printTree(TreeNode* root){
            if(!root) return;
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
    };

int main(){
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    s.printTree(root);
    cout << endl;
    s.invertTree(root);
    s.printTree(root);
}