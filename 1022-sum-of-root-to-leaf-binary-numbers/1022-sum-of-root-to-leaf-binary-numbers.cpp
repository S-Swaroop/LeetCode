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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0 ; 
        stack<pair<TreeNode* , int>> s ; 
        s.push({root , 0}) ;
        while(!s.empty()){
            auto node = s.top() ; 
            s.pop() ; 
            if(node.first){
                int curr_num = (node.second << 1) | node.first->val ; 
                if(!node.first->left && !node.first->right){
                    sum += curr_num ; 
                }else{
                    if(node.first->left)  s.push({node.first->left , curr_num}) ;
                    if(node.first->right) s.push({node.first->right , curr_num}) ;
                }
            }
        }
        return sum ; 
    }
};