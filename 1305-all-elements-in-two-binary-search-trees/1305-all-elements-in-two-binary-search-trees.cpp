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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans ; 
        stack<TreeNode*> s1 , s2 ; 
        pushLeft(root1 , s1) ; 
        pushLeft(root2 , s2) ; 
        while(!s1.empty() || !s2.empty()){ 
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2 ;
            TreeNode* node = s.top() ; 
            ans.push_back(node->val) ;
            s.pop() ; 
            pushLeft(node->right , s) ; 
        }
        return ans ; 
    }
private: 
    void pushLeft(TreeNode* node , stack<TreeNode*> &s) {
        while(node){
            s.push(node) ; 
            node = node->left ; 
        }
    }
};