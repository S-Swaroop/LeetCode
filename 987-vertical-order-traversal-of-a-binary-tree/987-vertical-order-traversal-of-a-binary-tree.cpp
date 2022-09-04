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
        for (int x = -999 ; x <= 999 ; x++) {
            if (f.find(x) == f.end()) {
                continue ;
            }
            vector<int> col ;
            for (int y = 0 ; y <= 999 ; y++) {
                col.insert(col.end() , f[x][y].begin() , f[x][y].end()) ;
            }
            ans.push_back(col) ;
        }
        return ans ;
    }
private: 
    unordered_map<int , unordered_map<int , multiset<int>>> f ; 
    void dfs (TreeNode *root , int x , int y) {
        if (root) {
            f[x][y].insert(root->val) ;
            dfs (root->left , x - 1 , y + 1) ;
            dfs (root->right , x + 1 , y + 1) ;
        }
    }
};