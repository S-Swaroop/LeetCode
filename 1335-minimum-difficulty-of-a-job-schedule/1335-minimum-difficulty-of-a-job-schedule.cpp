class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size())    return -1 ; 
        memset(memo , -1 , sizeof(memo)) ;
        return dp(0 , d , jobDifficulty , jobDifficulty.size()) ;
    }
private : 
    int memo[301][11] ; 
    int dp(int i , int k , vector<int>& jobDifficulty , int n){
        if(k == 1){
            return memo[i][k] = *max_element(jobDifficulty.begin() + i , jobDifficulty.end()) ; 
        }
        if(memo[i][k] != -1)    return memo[i][k] ; 
        int &res = memo[i][k] ; 
        res = INT_MAX ; 
        int _max = 0 ; 
        for(int j = i ; j <= n - k ; j++){
            _max = max(_max , jobDifficulty[j]) ;
            res = min(res , _max + dp(j + 1 , k - 1 , jobDifficulty , n)) ;
        }
        return res ; 
    }
};