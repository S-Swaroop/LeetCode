class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = 26 ;
        __init(n) ;
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                merge(eq[0] - 'a' , eq[3] - 'a') ;
            }
        }
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                if (same_parent(eq[0] - 'a' , eq[3] - 'a')) {
                    return false ;
                }
            }
        }
        return true ;
    }
private: 
    vector<int> parent , _rank ;
    void __init (int n) {
        parent.resize(n + 1 , 0) ;
        iota(parent.begin() , parent.end() , 0ll) ;
        _rank.resize(n + 1 , 0) ;
    }
    int find_parent (int v) {
        if (parent[v] == v) {
            return v ;
        } else {
            return parent[v] = find_parent(parent[v]) ;
        }
    }
    bool same_parent (int u , int v) {
        return find_parent(u) == find_parent(v) ;
    }
    void merge (int u , int v) {
        u = find_parent(u) ;
        v = find_parent(v) ;
        if (u == v) {
            return ;
        } else {
            if (_rank[u] < _rank[v]) {
                swap(u , v) ;
            }
            parent[u] = v ;
            if (_rank[u] == _rank[v]) {
                _rank[u]++ ;
            }
        }
    }
};