class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0 ;
        parent.resize(n , 0) ;
        _rank.resize(n , 0) ;
        iota(parent.begin() , parent.end() , 0) ;
        vector<int> comp(n , 0) ;
        for (auto &i : edges) {
            merge(i[0] , i[1]) ;
        }
        for (int i = 0 ; i < n ; i++) {
            comp[findParent(i)]++ ;
        }
        for (int i = 0 ; i < n ; i++) {
            ans += (long long)(n - comp[i]) * (long long)comp[i] ;
        }
        return ans / 2 ;
    }
private: 
    vector<int> parent , _rank ;
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
            } else if (_rank[v] > _rank[u]) {
                parent[v] = u ;
            } else {
                parent[u] = v ;
                _rank[u]++ ;
            }
        }
    }
};