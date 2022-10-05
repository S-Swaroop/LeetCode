class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0 ;
        for (int i = 0 ; i < (int)grid.size() ; i++) {
            for (int j = 0 ; j < (int)grid[0].size() ; j++) {
                if (isValid(i , j , grid)) {
                    ans += dfs (i , j , grid) ;
                }
            }
        }
        return ans ;
    }
private:
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , 1 , 0 , -1} ;
    bool isValid (int x , int y , vector<vector<int>> &grid) {
        return (x >= 0 && x < (int)grid.size() && y >= 0 && y < (int)grid[0].size() && grid[x][y] == 0) ;
    }
    bool notOnBorder (int x , int y , vector<vector<int>> &grid) {
        return (x > 0 && x < (int)grid.size() - 1 && y > 0 && y < (int)grid[0].size() - 1) ;
    }
    bool dfs (int x , int y , vector<vector<int>> &grid) {
        bool closed = notOnBorder(x , y , grid) ;
        grid[x][y] = 1 ;
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(x + dx[i] , y + dy[i] , grid)) {
                closed &= dfs(x + dx[i] , y + dy[i] , grid) ;
            }
        }
        return closed ;
    }
};