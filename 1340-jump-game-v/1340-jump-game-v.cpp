class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size() ; 
        memset(dp , -1 , sizeof(dp)) ;
        int ans = 0 ; 
        for (int i = 0 ; i < n ; i++) {
            if (dp[i] == -1)    dfs(arr , d , i) ;
            ans = max(ans , dp[i]) ;
        }
        return ans ; 
    }
private: 
    int dp[1001] ;
    int dfs(vector<int> &arr , int d , int index) {
        if(dp[index] != -1) return dp[index] ; 
        int n = arr.size() ;
        dp[index] = 1 ; 
        int left = 0 , right = 0 ; 
        for (int i = index - 1 ; i >= max(0 , index - d) ; i--) {
            if(arr[i] < arr[index]) left = max(left , dfs(arr , d , i)) ;
            else    break ; 
        }
        for (int i = index + 1 ; i <= min(n - 1 , index + d) ; i++) {
            if(arr[i] < arr[index]) right = max(right , dfs(arr , d , i)) ;
            else    break ; 
        }
        dp[index] = max(left , right) + 1 ; 
        return dp[index] ; 
    }
};