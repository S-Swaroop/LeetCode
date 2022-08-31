class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size() ;
        vector<vector<int>> ans ;
        vector<vector<char>> vis(n , vector<char> (m , '_')) ;
        for (int i = 0 ; i < n ; i++) {
            dfs ('P' , i , 0 , heights , vis , ans) ;
        }
        for (int i = 0 ; i < m ; i++) {
            dfs ('P' , 0 , i , heights , vis , ans) ;
        }
        for (int i = 0 ; i < n ; i++) {
            dfs ('A' , i , m - 1 , heights , vis , ans) ;
        }
        for (int i = 0 ; i < m ; i++) {
            dfs ('A' , n - 1 , i , heights , vis , ans) ;
        }
        return ans ;
    }
private: 
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid (int x , int y , vector<vector<int>> &heights) {
        return (x >= 0 && y >= 0 && x < (int)heights.size() && y < (int)heights[0].size()) ;
    }
    
    void dfs (char ocean , int x , int y , vector<vector<int>> &heights , vector<vector<char>> &vis , vector<vector<int>> &ans) {
        if (vis[x][y] != ocean) { // not visited by this ocean
            if (vis[x][y] != '_') {
                ans.push_back({x , y}) ;
            } 
            vis[x][y] = ocean ; 
            for (int i = 0 ; i < 4 ; i++) {
                if (isValid(x + dx[i] , y + dy[i] , heights) && heights[x][y] <= heights[x + dx[i]][y + dy[i]]) {
                    dfs (ocean , x + dx[i] , y + dy[i] , heights , vis , ans) ;
                }
            }
        } 
    }
};