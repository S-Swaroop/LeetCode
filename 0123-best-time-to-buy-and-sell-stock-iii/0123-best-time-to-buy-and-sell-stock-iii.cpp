class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        vector<vector<vector<int>>> dp (n + 1 , vector<vector<int>> (3 , vector<int> (2 , 0))) ;
        for (int i = 1 ; i <= 2 ; i++) {
            dp[0][i][1] = INT_MIN ;
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= 2 ; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0] , dp[i - 1][j][1] + prices[i - 1]) ;
                dp[i][j][1] = max(dp[i - 1][j][1] , dp[i - 1][j - 1][0] - prices[i - 1]) ;
            }
        }
        return dp[n][2][0] ;
    }
};