class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(memo , -1 , sizeof(memo)) ;
        return dp(0 , d , jobDifficulty) ;
    }
private: 
    int memo[301][11] ;
    int dp (int index , int daysLeft , vector<int> &jobDifficulty) {
        if (daysLeft > (int)jobDifficulty.size()) {
            return -1 ;
        } else if (index >= (int)jobDifficulty.size()) {
            return 0 ;
        } else if (memo[index][daysLeft] != -1) {
            return memo[index][daysLeft] ;  
        } else if (daysLeft == 1) {
            return memo[index][daysLeft] = *max_element(jobDifficulty.begin() + index , jobDifficulty.end()) ;
        } else {
            int &res = memo[index][daysLeft] ;
            res = INT_MAX ;
            int n = jobDifficulty.size() ;
            int _max = 0 ;
            for (int i = index ; i < n - daysLeft + 1 ; i++) {
                _max = max(_max , jobDifficulty[i]) ;
                res = min(res , dp(i + 1 , daysLeft - 1 , jobDifficulty) + _max) ;
            }
            return res ;
        }
    }
};