/*
给你一个二叉树的根节点 root ，检查它是否轴对称。

思路：
    如果同时满足下面的条件，两个树互为镜像：

        它们的两个根结点具有相同的值
        每个树的右子树都与另一个树的左子树镜像对称
    我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，
    p 指针和 q 指针一开始都指向这棵树的根，
    随后 p 右移时，q 左移，p 左移时，q 右移。
    每次检查当前 p 和 q 节点的值是否相等，如果相等再判断左右子树是否对称。

*/

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
        bool isSymmetric(TreeNode* root) {
            return check(root->left, root->right);
        }
        bool check(TreeNode* p, TreeNode* q){
            //中止条件：左右节点都为空
            if(p == nullptr && q == nullptr) return true;
            //中止条件：左右节点有一个为空，或者值不相等
            if(p == nullptr || q == nullptr || p->val != q->val) return false;
            // 递归判断左右子树是否对称
            return check(p->left, q->right) && check(p->right, q->left);
        }
    };