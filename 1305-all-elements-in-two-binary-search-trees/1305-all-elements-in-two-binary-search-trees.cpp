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
            TreeNode* node = nullptr ; 
            if(s1.empty()){
                node = s2.top() ; 
                s2.pop() ; 
                ans.push_back(node->val) ; 
                pushLeft(node->right , s2) ; 
            } else if (s2.empty()) {
                node = s1.top() ; 
                s1.pop() ; 
                ans.push_back(node->val) ; 
                pushLeft(node->right , s1) ; 
            } else {
                if(s1.top()->val <= s2.top()->val){
                    node = s1.top() ; 
                    s1.pop() ;
                    ans.push_back(node->val) ; 
                    pushLeft(node->right , s1) ; 
                } else {
                    node = s2.top() ; 
                    s2.pop() ; 
                    ans.push_back(node->val) ; 
                    pushLeft(node->right , s2) ; 
                }
            }
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