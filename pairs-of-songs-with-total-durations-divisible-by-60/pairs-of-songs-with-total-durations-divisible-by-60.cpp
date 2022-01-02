class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> f(60 , 0) ; 
        for(auto i : time){
            f[i % 60]++ ; 
        }
        int ans = (f[0] * (f[0] - 1)) / 2 ;
        ans += (f[30] * (f[30] - 1)) / 2 ;
        for(int i = 1 ; i < 30 ; i++){
            ans += f[i] * f[60 - i] ;
        }
        return ans ;
    }
};