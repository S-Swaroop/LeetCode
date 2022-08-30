class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        memo.resize(n , vector<int> (m , 0)) ;
        int ans = 0 ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                ans = (ans + dp(i , j , grid)) % MOD ;
            }
        }
        return ans ;
    }
private: 
    int MOD = 1e9 + 7 ;
    vector<vector<int>> memo ;
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid (int x , int y , vector<vector<int>> &grid) {
        return (x >= 0 && x < (int)grid.size() && y >= 0 && y < (int)grid[0].size()) ;
    }
    
    int dp (int x , int y , vector<vector<int>> &grid) {
        if (memo[x][y]) {
            return memo[x][y] ;
        } else {
            int res = 1 ;
            for (int i = 0 ; i < 4 ; i++) {
                if (isValid(x + dx[i] , y + dy[i] , grid) && grid[x + dx[i]][y + dy[i]] > grid[x][y]) {
                    res = (res + dp(x + dx[i] , y + dy[i] , grid)) % MOD ;
                }
            }
            return memo[x][y] = res ;
        }
    }
};