class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        make_set(edges.size()) ; 
        for(auto &i : edges){
            if(!merge(i[0] , i[1])){
                return i ; 
            }
        }
        return {} ; 
    }
private: 
    int par[1001] , _rank[1001] ; 
    void make_set(int n){
        for(int i = 0 ; i <= n ; i++)   par[i] = i , _rank[i] = 1 ; 
    }
    int findPar(int v){
        if(par[v] == v) return v ; 
        else    return par[v] = findPar(par[v]) ; 
    }
    bool merge(int u , int v){
        u = findPar(u) ;
        v = findPar(v) ; 
        if(u == v){
            return false ; 
        }else{
            if(_rank[u] < _rank[v]){
                par[u] = v ; 
            }else if(_rank[v] == _rank[u]){
                par[v] = u ;
            }else{
                par[u] = v ; 
                _rank[u] += _rank[v] ; 
            }
            return true ; 
        }
    }
};