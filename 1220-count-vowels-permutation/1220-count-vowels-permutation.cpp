class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7 ;
        vector<char> vowels = {'a' , 'e' , 'i' , 'o' , 'u'} ;
        vector<vector<long long int>> dp(n , vector<long long int> (5 , 1ll)) ; 
        for (int i = 1 ; i < n ; i++) {
            for (int j = 0 ; j < 5 ; j++) {
                if (j == 0) {
                    dp[i][j] *= (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) ;
                } else if (j == 1) {
                    dp[i][j] *= (dp[i - 1][0] + dp[i - 1][2]) ; 
                } else if (j == 2) {
                    dp[i][j] *= (dp[i - 1][1] + dp[i - 1][3]) ; 
                } else if (j == 3) {
                    dp[i][j] *= dp[i - 1][2] ; 
                } else {
                    dp[i][j] *= (dp[i - 1][2] + dp[i - 1][3]) ; 
                }
                dp[i][j] %= mod ;
            }
        }
        // for (int i = 0 ; i < n ; i++) {
        //     for (int j = 0 ; j < 5 ; j++) {
        //         cout << dp[i][j] << " " ;
        //     }
        //     cout << endl ;
        // }
        int ans = 0 ; 
        for (int i = 0 ; i < 5 ; i++) {
            ans = (ans + dp[n - 1][i]) % mod ;
        }
        return ans ;
    }
};