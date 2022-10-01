class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0 ; 
        }
        int n = s.length() ; 
        vector<int> dp(n + 1 , 0) ;
        dp[0] = 1 ; 
        dp[1] = (s[0] <= '9' && s[0] >= '1') ;
        for (int i = 2 ; i <= n ; i++) {
            dp[i] = dp[i - 1] * (s[i - 1] <= '9' && s[i - 1] >= '1') ;
            int x = num(s[i - 2] , s[i - 1]) ;
            dp[i] += dp[i - 2] * (x >= 10 && x <= 26) ;
        }
        return dp[n] ;
    }
private: 
    int memo[101] ;
    int dp (int index , string s) {
        if (index >= s.length()) {
            return 1 ;
        } else if (memo[index] != -1) {
            return memo[index] ;
        } else {
            int &res = memo[index] ;
            res = 0 ;
            if (s[index] >= '1' && s[index] <= '9') {
                res += dp (index + 1 , s) ;
            }
            if (index < s.length() - 1) {
                int x = num(s[index] , s[index + 1]) ; 
                if (x >= 10 && x <= 26) {
                    res += dp (index + 2 , s) ;
                }
            }
            return res ;
        }
    }
    int num (char a , char b) {
        return ((a - '0') * 10) + (b - '0') ;
    }
};