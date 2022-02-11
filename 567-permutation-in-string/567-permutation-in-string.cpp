class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length() , m = s1.length() ;
        
        if (m > n) {
            return false ; 
        }
        
        vector<int> f1(26 , 0) , f2(26 , 0) ; 
        
        for (char &c : s1)  f1[c - 'a']++ ;
        
        for (int i = 0 ; i < m ; i++) {
            f2[s2[i] - 'a']++ ;
        }
        if (f1 == f2) {
            return true ; 
        }
        for (int i = m ; i < n ; i++) { 
            f2[s2[i] - 'a']++ ;
            f2[s2[i - m] - 'a']-- ;
            if (f1 == f2) {
                return true ; 
            }
        }
        
        return false ;
    }
};