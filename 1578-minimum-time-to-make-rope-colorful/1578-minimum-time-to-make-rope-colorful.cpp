class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0 ;
        for (int i = 0 ; i < colors.length() ; i++) {
            int j = i + 1 ; 
            ans += neededTime[i] ;
            int _max = neededTime[i] ;
            while (j < colors.length() && colors[j] == colors[i]) {
                _max = max(_max , neededTime[j]) ;
                ans += neededTime[j] ;
                j++ ;
            }
            ans -= _max ;
            i = j - 1 ;
        }
        return ans ;
    }
};