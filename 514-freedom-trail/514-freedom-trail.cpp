class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memset(memo , -1 , sizeof(memo)) ;
        return dp(0 , 0 , ring , key) ; 
    }
private: 
    int memo[1001][1001] ; 
    int dp(int curr_ring , int curr_key , string &ring , string &key){
        int n = ring.length() ; 
        int m = key.length() ; 
        if(curr_key == m)   return 0 ; 
        int &res = memo[curr_ring][curr_key] ;
        if(res != -1)   return res ; 
        res = INT_MAX ; 
        for(int i = 0 ; i < n ; i++){
            if(ring[i] == key[curr_key]){
                int steps = min({abs(curr_ring - i) , abs(n + i - curr_ring) , abs(n - i + curr_ring)}) ; 
                res = min(res , steps + 1 + dp(i , curr_key + 1 , ring , key)) ;
            }
        }
        return res ; 
    }
};