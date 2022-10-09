class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod = 1e9 + 7 ;
        int n = grid.size() , m = grid[0].size() ;
        // int dp[n][m][k] ;
        // memset(dp , 0 , sizeof(int) * n * m * k) ;
        // dp[0][0][grid[0][0] % k]++ ;
        // for (int i = 1 ; i < m ; i++) {
        //     for (int j = 0 ; j < k ; j++) {
        //         dp[0][i][(j + grid[0][i]) % k] = dp[0][i - 1][j] % mod ;
        //     }
        // }
        // for (int i = 1 ; i < n ; i++) {
        //     for (int j = 0 ; j < k ; j++) {
        //         dp[i][0][(j + grid[i][0]) % k] = dp[i - 1][0][j] % mod ;
        //     }
        // }
        // for (int i = 1 ; i < n ; i++) {
        //     for (int j = 1 ; j < m ; j++) {
        //         for (int _k = 0 ; _k < k ; _k++) {
        //             dp[i][j][(grid[i][j] + _k) % k] = (dp[i - 1][j][_k] + dp[i][j - 1][_k]) % mod ;
        //         }
        //     }
        // }
        // return dp[n - 1][m - 1][0] ;
        vector<vector<vector<int>>> dp(2 , vector<vector<int>> (m , vector<int> (k , 0))) ;
        // int dp[2][m][k] ;
        // memset(dp , 0 , sizeof(int) * 2 * m * k) ;
        dp[0][0][grid[0][0] % k]++ ;
        for (int j = 1 ; j < m ; j++) {
            for (int _k = 0 ; _k < k ; _k++) {
                dp[0][j][(grid[0][j] + _k) % k] = dp[0][j - 1][_k] ;
            }
        }
        for (int i = 1 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                for (int _k = 0 ; _k < k ; _k++) {
                    if (j > 0) {
                        dp[1][j][(grid[i][j] + _k) % k] = (dp[0][j][_k] + dp[1][j - 1][_k]) % mod ;
                    } else {
                        dp[1][j][(grid[i][j] + _k) % k] = dp[0][j][_k] ;
                    }
                }
            }
            // if (i != n - 1)
            swap(dp[0] , dp[1]) ;
        }
        return dp[0][m - 1][0] ;
    }
};