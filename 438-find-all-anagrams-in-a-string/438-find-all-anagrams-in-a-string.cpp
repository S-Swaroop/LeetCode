class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length() ; 
        int m = p.length() ; 
        if (m > n){
            return {} ; 
        }
        vector<char> fs(26 , '0') , fp(26 , '0') ;
        vector<int> ans ; 
        for (int i = 0 ; i < m ; i++){
            fs[s[i] - 'a']++ ; 
            fp[p[i] - 'a']++ ; 
        }
        if (fs == fp)  ans.push_back(0) ; 
        for (int i = m ; i < n ; i++){
            fs[s[i] - 'a']++ ; 
            fs[s[i - m] - 'a']-- ;
            if (fs == fp){
                ans.push_back(i - m + 1) ; 
            }
        }
        return ans ;
    }
};