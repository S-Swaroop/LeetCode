class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0 , r = s.length() - 1 ; 
        auto isPalindrome = [&] (int i , int j) -> bool {
            if (i >= j) return true ;
            while (i <= j) {
                if (s[i] != s[j]) {
                    return false ;
                }
                i++ ; 
                j-- ;
            }
            return true ;
        };
        while (l <= r) {
            if (s[l] != s[r]) {
                return isPalindrome(l + 1 , r) || isPalindrome(l , r - 1) ;
            }
            l++ ;
            r-- ;
        }
        return true ;
    }
};