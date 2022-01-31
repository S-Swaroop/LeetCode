class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length() ;
        vector<int> dp(n + 1 , 0) ;
        int l = min(n - 1 , minJump) ;
        int r = min(n - 1 , maxJump) ;
        dp[l]++ ;
        dp[r + 1]-- ;
        for (int i = 1 ; i < n ; i++) {
            dp[i] += dp[i - 1] ;
            if (s[i] == '1') continue ;
            if (dp[i]) {
                if (i == n - 1) return true ;
                l = i + minJump ;
                r = min(n - 1 , i + maxJump) ;
                if (l <= r) {
                    dp[l]++ ;
                    dp[r + 1]-- ; 
                }
            }
        }
        return false;
    }
};