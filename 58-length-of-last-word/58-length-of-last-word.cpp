class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() , len = 0 ; 
        for (int i = n - 1 ; i >= 0 ; i--) {
            if (isalpha(s[i])) {
                len++ ; 
            } else if (len > 0) {
                break ;
            }
        }
        return len ;
    }
};