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
        vector<int> list ; 
        traverse(root1 , list) ; 
        traverse(root2 , list) ;
        sort(list.begin() , list.end()) ;
        return list ;
    }
private: 
    void traverse(TreeNode* root , vector<int> &list){
        if(!root)   return ; 
        queue<TreeNode*> s ; 
        s.push(root) ;
        while(!s.empty()){
            auto node = s.front() ; 
            s.pop() ; 
            list.push_back(node->val) ; 
            if(node->left)  s.push(node->left) ; 
            if(node->right) s.push(node->right) ;
        }
    }
};