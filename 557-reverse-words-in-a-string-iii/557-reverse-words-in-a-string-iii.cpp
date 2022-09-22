class Solution {
public:
    string reverseWords(string s) {
        string word = "" , ans = "" ; 
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == ' ') {
                reverse(word.begin() , word.end()) ;
                ans += word ; 
                ans += " " ;
                word = "" ;
            } else {
                word += s[i] ;
            }
        }
        if (!word.empty()) {
            reverse(word.begin() , word.end()) ;
            ans += word ; 
        }
        return ans ;
    }
};