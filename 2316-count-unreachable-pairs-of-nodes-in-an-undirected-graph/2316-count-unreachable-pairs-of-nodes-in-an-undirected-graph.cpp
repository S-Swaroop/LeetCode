class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0 ;
        parent.resize(n , 0) ;
        _size.resize(n , 1) ;
        _rank.resize(n , 0) ;
        iota(parent.begin() , parent.end() , 0) ;
        vector<int> comp(n , 0) ;
        for (auto &i : edges) {
            merge(i[0] , i[1]) ;
        }
        // for (int i = 0 ; i < n ; i++) {
        //     comp[findParent(i)]++ ;
        // }
        for (int i = 0 ; i < n ; i++) {
            ans += (long long)(n - _size[i]) * (long long)_size[i] ;
        }
        return (ans >> 1) ;
    }
private: 
    vector<int> parent , _rank , _size ;
    int findParent (int u) {
        if (parent[u] == u) {
            return u ;
        } else {
            return parent[u] = findParent(parent[u]) ;
        }
    }
    void merge (int u , int v) {
        u = findParent(u) ;
        v = findParent(v) ;
        if (u != v) {
            if (_rank[u] > _rank[v]) {
                parent[u] = v ;
                _size[v] += _size[u] ;
                _size[u] = 0 ;
            } else if (_rank[v] > _rank[u]) {
                parent[v] = u ;
                _size[u] += _size[v] ;
                _size[v] = 0 ;
            } else {
                parent[u] = v ;
                _rank[u]++ ;
                _size[v] += _size[u] ;
                _size[u] = 0 ;
            }
        }
    }
};