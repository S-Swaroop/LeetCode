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
    vector<double> averageOfLevels(TreeNode* root) {
        int level_size = 1 ;
        queue<TreeNode*> q ; 
        q.push(root) ;
        vector<double> average ;
        while (!q.empty()) {
            double sum = 0.0 ; 
            for (int i = 0 ; i < level_size ; i++) {
                sum += q.front()->val ;
                if (q.front()->left)    q.push(q.front()->left) ;
                if (q.front()->right)   q.push(q.front()->right) ;
                q.pop() ;
            }
            average.push_back(sum / level_size) ;
            level_size = (int)q.size() ;
        }
        return average ;
    }
};