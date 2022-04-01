class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        memset(memo , -1 , sizeof(memo)) ;
        int n = nums.size() ; 
        vector<int> pref(n + 1 , 0) ;
        for (int i = 0 ; i < n ; i++) {
            pref[i + 1] += pref[i] + nums[i] ;
        }
        return dp(0 , m , pref) ;
    }
private: 
    int memo[1001][51] ;
    int dp (int i , int m , vector<int> &pref) {
        int n = pref.size() - 1 ;
        if (memo[i][m] != -1) {
            return memo[i][m] ;
        }
        if (m == 1) {
            return memo[i][m] = pref[n] - pref[i] ;
        }
        int res = INT_MAX ; 
        for (int j = i ; j <= n - m ; j++) {
            int sum = pref[j + 1] - pref[i] ;
            int best = max(sum , dp (j + 1 , m - 1 , pref)) ;
            res = min(res , best) ;
            if (sum >= best) {
                break ;
            }
        }
        return memo[i][m] = res ;
    }
};