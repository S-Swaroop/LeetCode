class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0 ;
        vector<int> f(852 , 0) ;
        for (string &s : words) {
            if (f[(s[1] - 'a' + 1) + ((s[0] - 'a' + 1) * 31)]) {
                ans += 4 ;
                f[(s[1] - 'a' + 1) + ((s[0] - 'a' + 1) * 31)]-- ;
            } else {
                f[(s[0] - 'a' + 1) + ((s[1] - 'a' + 1) * 31)]++ ;
            }
        }
        for (string &s : words) {
            if (s[0] == s[1] && f[(s[0] - 'a' + 1) + ((s[1] - 'a' + 1) * 31)]) {
                ans += 2 ; 
                break ;
            }
        }
        return ans ;
    }
};