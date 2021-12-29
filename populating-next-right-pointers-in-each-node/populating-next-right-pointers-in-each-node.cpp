/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> traversal ; 
    void BFS(Node* root){
        queue<Node*> q ;
        q.push(root) ;
        while(!q.empty()){
            int size = q.size() ; 
            vector<Node*> level ; 
            for(int i = 0 ; i < size ; i++){
                auto node = q.front() ; 
                level.push_back(node) ; 
                q.pop() ;
                if(node->left)	q.push(node->left) ; 
                if(node->right)	q.push(node->right) ; 
            }
            traversal.push_back(level) ; 
        }
    }
    Node* connect(Node* root) {
        if(!root)   return root ; 
        BFS(root) ; 
        for(auto &level : traversal){
            for(int i = 0 , n = level.size() ; i < n - 1 ; i++){
                level[i]->next = level[i+1] ;
            }
            level.back()->next = NULL ; 
        }
        return root ; 
    }
};