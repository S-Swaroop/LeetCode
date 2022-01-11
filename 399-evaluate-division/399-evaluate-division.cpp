class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string , vector<pair<string,double>>> adj ; 
        int n = equations.size() ; 
        for(int i = 0 ; i < n ; i++){
            adj[equations[i][0]].push_back({equations[i][1] , values[i]}) ;
            adj[equations[i][1]].push_back({equations[i][0] , 1.0 / values[i]}) ;
        }
        auto bfs = [&](string node , string target){
            if(adj.find(node) == adj.end()){
                return -1.0 ; 
            }
            unordered_map<string , bool> vis ; 
            queue<pair<string, double>> s ;
            s.push({node , 1.0}) ;
            while(!s.empty()){
                auto f = s.front() ; 
                vis[f.first] = 1 ; 
                if(f.first == target){
                    return  f.second ; 
                }
                s.pop() ;
                for(auto &i : adj[f.first]){
                    if(!vis[i.first]){
                        s.push({i.first , f.second * i.second}) ;
                    }
                }
            }
            return -1.0 ; 
        };
        vector<double> ans ; 
        for(auto &q : queries){
            ans.push_back(bfs(q[0] , q[1])) ;
        }
        return ans ; 
    }
};