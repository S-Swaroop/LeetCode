class Solution {
public:
    string countAndSay(int n , string s = "1") {
        if (n == 1) {
            return s ;
        } else {
            string str = "" ; 
            int i = 0 , j , len = 1 ; 
            while (i < s.length()) {
                j = i ; 
                while (j < s.length() && s[j] == s[i]) {
                    j++ ;
                }
                str += to_string(j - i) + s[i] ;
                i = j ;
            }
            return countAndSay(n - 1 , str) ;
        }
    }
};