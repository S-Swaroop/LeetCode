class Solution {
public:
    int numSplits(string s) {
        vector<int> left(26 , 0) , right(26 , 0) ;
        int l = 0 , r = 0 , ans = 0 ;
        for (char &i : s) {
            r += (++right[i - 'a'] == 1) ;
        }
        for (char &i : s) {
            l += (++left[i - 'a'] == 1) ;
            r -= (--right[i - 'a'] == 0) ;
            ans += (r == l) ;
        }
        return ans ; 
    }
};