class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        dp.resize(n , vector<int>(m , 0)) ;
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans , dfs(i , j , matrix)) ;
            }
        }
        return ans ;
    }
private: 
    vector<vector<int>> dp ;
    int dx[4] = {-1 , 0 , 1 , 0} ;
    int dy[4] = {0 , -1 , 0 , 1} ;
    
    bool isValid(int x , int y){
        if(x < 0 || y < 0 || x >= dp.size() || y >= dp[0].size()) return false ; 
        else    return true ; 
    }
    
    int dfs(int x , int y , vector<vector<int>> &matrix){
        if(dp[x][y])    return dp[x][y] ;
        for(int i = 0 ; i < 4 ; i++){
            if(isValid(x + dx[i] , y + dy[i]) && matrix[x + dx[i]][y + dy[i]] > matrix[x][y]){
                dp[x][y] = max(dp[x][y] , dfs(x + dx[i] , y + dy[i] , matrix)) ;
            }   
        }
        return ++dp[x][y] ; 
    }
};