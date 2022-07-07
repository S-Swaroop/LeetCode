class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 , j = s.length() - 1 ; 
        while (i < j) {
            if (!iswalnum(s[i])) {
                i++ ; 
                continue ;
            }
            if (!iswalnum(s[j])) {
                j-- ; 
                continue ;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false ;
            } else {
                i++ ; 
                j-- ;
            }
        }
        return true ;
    }
private: 
    string trim(string s){
        string res = "" ; 
        for(char c : s){
            if(isalpha(c))   res += tolower(c) ; 
        }
        return res ; 
    }
};