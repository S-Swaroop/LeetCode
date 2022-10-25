class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0 ;
        // vector<int> f(781 , 0) ;
        unordered_map<int , int> f ;
        for (string &s : words) {
            if (f[(s[1] - 'a' + 1) + ((s[0] - 'a' + 1) * 29)]) {
                ans += 4 ;
                f[(s[1] - 'a' + 1) + ((s[0] - 'a' + 1) * 29)]-- ;
            } else {
                f[(s[0] - 'a' + 1) + ((s[1] - 'a' + 1) * 29)]++ ;
            }
        }
        for (string &s : words) {
            if (s[0] == s[1] && f[(s[0] - 'a' + 1) + ((s[1] - 'a' + 1) * 29)]) {
                ans += 2 ; 
                break ;
            }
        }
        return ans ;
    }
};