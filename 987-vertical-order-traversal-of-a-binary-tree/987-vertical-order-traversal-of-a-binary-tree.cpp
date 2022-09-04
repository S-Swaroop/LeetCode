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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs (root , 0 , 0) ;
        vector<vector<int>> ans ;
        for (auto i : f) {
            vector<int> col ;
            for (auto j : i.second) {
                col.insert(col.end() , j.second.begin() , j.second.end()) ;
            }
            ans.push_back(col) ;
        }
        return ans ;
    }
private: 
    map<int , map<int , multiset<int>>> f ; 
    void dfs (TreeNode *root , int x , int y) {
        if (root) {
            f[x][y].insert(root->val) ;
            dfs (root->left , x - 1 , y + 1) ;
            dfs (root->right , x + 1 , y + 1) ;
        }
    }
};