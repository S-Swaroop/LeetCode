class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size() ; 
        vector<int> diff(n , 0) ; 
        for (int i = 1 ; i < n ; i++) {
            diff[i] = a[i] - a[i - 1] ; 
        }
        int ans = 0 ; 
        vector<int> dp(n , 0) ; 
        for (int i = 2 ; i < n ; i++) {
            if (diff[i] == diff[i - 1])  
                dp[i] = dp[i-1] + 1 ; 
            else    
                dp[i] = 0 ; 
            ans += dp[i] ; 
        } 
        return ans ; 
    }
};