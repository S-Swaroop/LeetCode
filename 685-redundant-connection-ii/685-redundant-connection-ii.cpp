class Solution {
public:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size() ; 
        vector<int> edgeA , edgeB ; 
        vector<int> parent(n + 1 , 0) ; 
        for(auto &edge : edges){
            if(parent[edge[1]] == 0){
                parent[edge[1]] = edge[0] ; 
            }else{
                edgeA = {parent[edge[1]] , edge[1]} ;
                edgeB = edge ; 
                edge[1] = 0 ; //marking as redundant
            }
        }
        for(int i = 1 ; i <= n ; i++){
            parent[i] = i ; 
        }
        for(auto &edge : edges){
            if(edge[1] == 0)    continue ; 
            else{
                int u = edge[0] , v = edge[1] , parentu = root(parent , u) ; 
                if(parentu == v){
                    if(edgeA.empty())   return edge ; 
                    return edgeA ; 
                }
                parent[v] = u ; 
            }
        }
        return edgeB ; 
    }
};