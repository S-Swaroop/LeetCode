class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "" ;
        int n = s.length() ;
        vector<vector<bool>> dp (n , vector<bool> (n , false)) ; 
        for (int i = 0 ; i < n ; i++) {
            dp[i][i] = true ; 
            if (i < n - 1) {
                dp[i][i + 1] = (s[i] == s[i + 1]) ;
            }
        }
        for (int i = n - 3 ; i >= 0 ; i--) {
            for (int j = i + 2 ; j < n ; j++) {
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]) ;
            }
        }
        int strt = 0 , len = 0 ; 
        for (int i = 0 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                if (dp[i][j]) {
                    if (len < (j - i + 1)) {
                        strt = i ; 
                        len = j - i + 1 ;
                    }
                }
            }
        }
        return s.substr(strt , len) ; 
    }
};