class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n = rowConditions.size() , m = colConditions.size() ;
        vector<int> X(k + 1 , 0) , Y(k + 1 , 0) ;
        vector<int> row_adj[k + 1] , col_adj[k + 1] ;
        vector<bool> vis(k + 1 , false) ;
        for (auto i : rowConditions) {
            row_adj[i[0]].push_back(i[1]) ;
        }
        for (auto i : colConditions) {
            col_adj[i[0]].push_back(i[1]) ;
        }
        if (!possible(k , row_adj) || !possible(k , col_adj)) {
            return {} ;
        }
        stack<int> R , C ;
        for (int i = 1 ; i <= k ; i++) {
            if (!vis[i]) {
                topoSort(i , vis , R , row_adj) ;
            }
        }
        fill(vis.begin() , vis.end() , false) ;
        for (int i = 1 ; i <= k ; i++) {
            if (!vis[i]) {
                topoSort(i , vis , C , col_adj) ;
            }
        }
        vector<vector<int>> ans(k , vector<int> (k , 0)) ;
        for (int i = 0 ; i < k ; i++) {
            X[R.top()] = i ;
            Y[C.top()] = i ;
            R.pop() ; 
            C.pop() ;
        }
        for (int i = 1 ; i <= k ; i++) {
            ans[X[i]][Y[i]] = i ;
        }
        return ans ;
    }
private: 
    void topoSort (int node , vector<bool> &vis , stack<int> &st , vector<int> adj[]) {
        vis[node] = true ;
        for (int i : adj[node]) {
            if (!vis[i]) {
                topoSort(i , vis , st , adj) ;
            } 
        }
        st.push(node) ;
    }
    bool possible (int n , vector<int> adj[]) {
        vector<int> color(n + 1 , -1) ;
        bool flag = true ;
        for (int i = 1 ; i <= n ; i++) {
            if (color[i] == -1) {
                flag &= dfs(i , color , adj) ;
            }
        }
        return flag ;
    }
    bool dfs (int node , vector<int> &color , vector<int> adj[]) {
        color[node] = 0 ;
        bool flag = true ;
        for (int i : adj[node]) {
            if (color[i] == -1) {
                flag &= dfs(i , color , adj) ;
            } else if (color[i] == 0) {
                return false ;
            }
        }
        color[node] = 1 ;
        return flag ;
    }
};