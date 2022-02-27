class Solution {
public:
    class triplet {
    public :
        int node , mask , cost ; 
        triplet(int _node , int _mask , int _cost) {
            this -> node = _node ; 
            this -> mask = _mask ; 
            this -> cost = _cost ; 
        };
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        queue<triplet> q ; 
        set<pair<int , int>> vis ; 
        for (int i = 0 ; i < n ; i++) {
            triplet curr_node (i , (1 << i) , 1) ;
            vis.insert({i , (1 << i)}) ;
            q.push(curr_node) ;
        }
        while (!q.empty()) {
            triplet curr = q.front() ; 
            q.pop() ; 
            if (curr.mask == ((1 << n) - 1)) {
                return curr.cost - 1 ;
            }
            for (int &i : graph[curr.node]) {
                int both_vis_mask = curr.mask ; 
                both_vis_mask = both_vis_mask | (1 << i) ;
                triplet curr_node(i , both_vis_mask , curr.cost + 1) ;
                if (vis.find({i , both_vis_mask}) == vis.end()) {
                    vis.insert({i , both_vis_mask}) ;
                    q.push(curr_node) ;
                }
            }
        }
        return -1 ;
    }
};