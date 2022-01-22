class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1 , 0) ;
        dp[1] = 1 ; 
        dp[0] = 0 ; 
        for(int i = 0 ; i <= n ; i++){
            for(int j = 1 ; j * j + i <= n ; j++){
                dp[i + j * j] = dp[i + j * j] || (!dp[i]) ; 
            }
        }
        return dp[n] ; 
    }
};