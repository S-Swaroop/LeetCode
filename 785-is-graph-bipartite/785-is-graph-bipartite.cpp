class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size() , -1) ;
        auto BFS = [&] (int node) -> bool { 
            queue<int> q ; 
            q.push(node) ;
            color[node] = 0 ;
            while (!q.empty()) {
                int u = q.front() ;
                q.pop() ; 
                for (int &v : graph[u]) {
                    if (color[v] == color[u]) {
                        return false ;
                    }
                    if (color[v] != -1) continue ;
                    color[v] = (color[u] + 1) % 2 ;
                    q.push(v) ;
                }
            }
            return true ;
        };
        bool ans = true ;
        for (int i = 0 ; i < graph.size() ; i++) {
            if (color[i] == -1) {
                ans &= BFS(i) ;
            }
        }
        return ans ;
    }
};