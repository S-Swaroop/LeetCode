class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = accumulate(neededTime.begin() , neededTime.end() , 0) ;
        for (int i = 0 ; i < colors.length() ; i++) {
            int j = i + 1 ; 
            int _max = neededTime[i] ;
            while (j < colors.length() && colors[j] == colors[i]) {
                _max = max(_max , neededTime[j]) ;
                j++ ;
            }
            ans -= _max ;
            i = j - 1 ;
        }
        return ans ;
    }
};