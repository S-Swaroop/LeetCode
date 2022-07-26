/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root , p , q) ; 
        return lca ;
    }
private:
    TreeNode *lca = nullptr ;
    bool search(TreeNode *root , TreeNode * p , TreeNode *q) {
        if (!root)  return false ; 
        int left = search(root->left , p , q) ;
        int right = search(root->right , p , q) ;
        int mid = root == q || root == p ; 
        if (left + right + mid >= 2) {
            if (!lca) {
                lca = root ; 
            }
        }
        return (right + left + mid > 0) ;
    }
};