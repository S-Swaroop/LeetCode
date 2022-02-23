/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return node ;
        unordered_map<Node* , Node*> done ;
        Node* clone = new Node(node->val , {}) ;
        done[node] = clone ;
        queue<Node*> q ; 
        q.push(node) ;
        while (!q.empty()) {
            Node *curr_node = q.front() ; 
            q.pop() ;
            for (Node* neighbor : curr_node->neighbors) {
                if (done.find(neighbor) == done.end()) {
                    done[neighbor] = new Node(neighbor->val , {}) ;
                    q.push(neighbor) ;
                }
                done[curr_node]->neighbors.push_back(done[neighbor]) ;
            }
        }
        return clone ;
    }
};