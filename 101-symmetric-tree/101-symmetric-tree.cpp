/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || f(root->left , root->right) ;
    }
private: 
    bool f (TreeNode *left , TreeNode *right) {
        if (!left || !right) {
            return left == right ;
        } else if (left->val != right->val) {
            return false ;
        } else {
            return f(left->left , right->right) && f (left->right , right->left) ;
        }
    }
};