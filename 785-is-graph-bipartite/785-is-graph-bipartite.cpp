class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size() , -1) ;
        bool answer = true ;
        for (int i = 0 ; i < graph.size() ; i++) {
            if (color[i] == -1) {
                color[i] = 0 ; 
                answer &= dfs (i , graph , color) ;
            }
        }
        return answer ;
    }
private: 
    bool dfs (int node , vector<vector<int>> &graph , vector<int> &color) {
        bool res = true ;
        for (int &i : graph[node]) {
            if (color[i] == color[node]) {
                return false ; 
            } else if (color[i] != -1) {
                continue ; 
            } else {
                color[i] = (color[node] + 1) % 2 ; 
                res &= dfs (i , graph , color) ;
            }
        }
        return res ;
    }
};