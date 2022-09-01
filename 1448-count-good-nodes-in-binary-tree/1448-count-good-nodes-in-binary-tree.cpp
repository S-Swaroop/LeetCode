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
    int goodNodes(TreeNode* root , int max_yet = INT_MIN) {
        return (root ? (root->val >= max_yet) + goodNodes(root->right , max(root->val , max_yet)) + goodNodes(root->left , max(root->val , max_yet)) : 0) ;
    }
private: 
    void dfs (TreeNode *root , int max_yet , int &count) {
        if (!root)  return ;
        if (max_yet <= root->val) {
            count++ ;
        }
        dfs (root->left , max(max_yet , root->val) , count) ;
        dfs (root->right , max(max_yet , root->val) , count) ;
    }
};