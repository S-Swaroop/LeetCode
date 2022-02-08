class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) {
            return -1 ;
        }
        cout << (int)connections.size() << endl ;
        int components = 0 ;
        make_set(n) ; 
        for (vector<int> &i : connections) {
            merge(i[0] , i[1]) ; 
        }
        for (int i = 0 ; i < n ; i++) {
            if (parent[i] == i) {
                components++ ;
            }
        }
        return components - 1 ;
    }
private:
    vector<int> _rank , parent ;
    void make_set(int n) {
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