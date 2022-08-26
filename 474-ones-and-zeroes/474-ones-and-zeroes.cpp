class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans = 0 ;
        vector<vector<int>> dp (m + 1 , vector<int> (n + 1 , 0)) ;
        for (auto &s : strs) {
            int ones = count(s.begin() , s.end() , '1') ;
            int zeros = (int)s.length() - ones ;
            for (int i = m ; i >= zeros ; i--) {
                for (int j = n ; j >= ones ; j--) {
                    dp[i][j] = max(dp[i][j] , dp[i - zeros][j - ones] + 1) ;
                    ans = max(ans , dp[i][j]) ;
                }
            }
        }
        return ans ;
    }
};