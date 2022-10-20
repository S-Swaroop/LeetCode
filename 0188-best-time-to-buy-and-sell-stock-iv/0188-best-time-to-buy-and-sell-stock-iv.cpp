class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ; 
        vector<vector<vector<long>>> dp (n + 1 , vector<vector<long>> (k + 1 , vector<long> (2 , 0))) ;
        for (int i = 1 ; i <= k ; i++) {
            dp[0][i][0] = 0 ;
            dp[0][i][1] = INT_MIN ;
        }
        for (int i = 1 ; i <= n ; i++) {
            dp[i][0][0] = 0 ;
            for (int j = 1 ; j <= k ; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0] , dp[i - 1][j][1] + prices[i - 1]) ;
                dp[i][j][1] = max(dp[i - 1][j][1] , dp[i - 1][j - 1][0] - prices[i - 1]) ;
            }
        }
        return dp[n][k][0] ;
    }
};