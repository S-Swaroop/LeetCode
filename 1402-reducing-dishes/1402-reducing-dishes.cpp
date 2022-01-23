class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end()) ;
        return dp(0 , 1 , satisfaction) ;
    }
private: 
    int memo[501][501] = {} ;
    int dp(int index , int time , vector<int> &satisfaction){
        if(index == satisfaction.size())    return 0 ; 
        if(memo[index][time]) return memo[index][time] ; 
        return memo[index][time] = max(dp(index + 1 , time , satisfaction) , satisfaction[index] * time + dp(index + 1 , time + 1 , satisfaction)) ;
    }
};