class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        int count = 0 ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (isValid(i , j , grid)) {
                    dfs(i , j , grid) ;
                    count++ ;
                }
            }
        }
        return count ;
    }
private: 
    int dx[4] = {-1 , 0 , 1 , 0} ; 
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid (int x , int y , vector<vector<char>> &grid) {
        return (x >= 0 && x < (int)grid.size() && y >= 0 && y < (int)grid[0].size() && grid[x][y] == '1') ;
    }
    
    void dfs (int x , int y , vector<vector<char>> &grid) {
        grid[x][y] = '0' ;
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i] , grid)) {
                dfs (x + dx[i] , y + dy[i] , grid) ;
            }
        }
    }
};