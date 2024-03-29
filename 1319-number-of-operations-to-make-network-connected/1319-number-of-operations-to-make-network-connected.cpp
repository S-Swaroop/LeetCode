class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) {
            return -1 ;
        }
        make_set(n) ; 
        for (vector<int> &i : connections) {
            merge(i[0] , i[1]) ; 
        }
        return components - 1 ;
    }
private:
    vector<int> _rank , parent ;
    int components ;
    void make_set(int n) {
        components = n ; 
        _rank.resize(n + 1 , 0) ; 
        parent.resize(n + 1 , 0) ;
        iota(parent.begin() , parent.end() , 0) ;
    }
    int find_parent(int v) {
        if (parent[v] == v) return v ;
        else    return parent[v] = find_parent(parent[v]) ;
    }
    void merge(int u , int v) {
        u = find_parent(u) ; 
        v = find_parent(v) ;
        if (u == v) {
            return ;
        }
        components-- ;
        if (_rank[u] < _rank[v]) {
            parent[u] = v ; 
        } else if (_rank[u] > _rank[v]) {
            parent[v] = u ; 
        } else {
            parent[u] = v ; 
            _rank[v]++ ;
        }
    }
};