class Solution {
public:
    bool isMatch(string s, string p) {
        int star = -1 , match = 0 ;
        int n = s.length() , m = p.length() , i = 0 , j = 0 ; 
        while (i < n) {
            if (j < m && (s[i] == p[j] || p[j] == '?')) {
                i++ ; 
                j++ ; 
            } else if (j < m && p[j] == '*') {
                star = j ; 
                match = i ; 
                j++ ; 
            } else if (star != -1) {
                match++ ; 
                j = star + 1 ;
                i = match ;
            } else {
                return false ;
            }
        }
        while (j < m && p[j] == '*') {
            j++ ; 
        }
        return j == m ;
    }
};