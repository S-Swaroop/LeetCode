class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ;
        memo.resize(n + 1 , vector<int> (m + 1 , 0)) ;
        int ans = 0 ;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                ans = max(ans , dp(i , j , matrix)) ;
            }
        }
        return ans ;
    }
private: 
    vector<vector<int>> memo ;
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid (int x , int y , vector<vector<int>> &matrix) {
        return (x >= 0 && x < (int)matrix.size() && y >= 0 && y < (int)matrix[0].size()) ;
    }
    
    int dp (int x , int y , vector<vector<int>> &matrix) {
        if (memo[x][y]) {
            return memo[x][y] ;
        } else {
            int res = 1 ;
            for (int i = 0 ; i < 4 ; i++) {
                if (isValid(x + dx[i] , y + dy[i] , matrix) && matrix[x + dx[i]][y + dy[i]] > matrix[x][y]) {
                    res = max(res , dp(x + dx[i] , y + dy[i] , matrix) + 1) ;
                }
            }
            return memo[x][y] = res ;
        }
    }
};