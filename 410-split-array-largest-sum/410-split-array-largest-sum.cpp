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
    int dp (int i , int m , vector<int> &pref) { // best answer till ith index , having made m sub arrays
        int n = pref.size() - 1 ;
        if (memo[i][m] != -1) {
            return memo[i][m] ;
        }
        if (m == 1) {
            return memo[i][m] = pref[n] - pref[i] ;
        }
        int &res = memo[i][m] ;
        res = INT_MAX ; 
        for (int j = i ; j <= n - m ; j++) {
            int curr_sub_sum = pref[j + 1] - pref[i] ;
            int largest_sub_sum = max(curr_sub_sum , dp (j + 1 , m - 1 , pref)) ;
            res = min(res , largest_sub_sum) ;
            if (curr_sub_sum >= largest_sub_sum) { // won't find any larger sum than this so break
                break ;
            }
        }
        return res ;
    }
};