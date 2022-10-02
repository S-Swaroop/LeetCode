class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(memo , -1 , sizeof(memo)) ;
        return dp(n , k , target) ;
    }
private: 
    int mod = 1e9 + 7 ;
    int memo[31][1001] ; 
    int dp (int n , int k , int target) {
        if (n == 0) {
            return (target == 0) ;
        } else if (memo[n][target] != -1) {
            return memo[n][target] ;
        } else {
            long long res = 0 ;
            for (int i = 1 ; i <= min(target , k) ; i++) {
                res = (res + dp(n - 1 , k , target - i)) % mod ;  
            }
            return memo[n][target] = res ;
        }
    }
};