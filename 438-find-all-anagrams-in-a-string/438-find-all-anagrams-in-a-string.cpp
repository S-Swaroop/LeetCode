class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length() , m = p.length() ; 
        if (n < m) {
            return {} ; 
        } else {
            vector<int> ans ; 
            vector<int> fs(26 , 0) , fp(26 , 0) ; 
            for (int i = 0 ; i < m ; i++) {
                fs[s[i] - 'a']++ ; 
                fp[p[i] - 'a']++ ; 
            }
            if (fs == fp) {
                ans.push_back(0) ; 
            }
            for (int r = m ; r < n ; r++) {// move window then check
                int l = r - (m - 1) ;
                fs[s[r] - 'a']++ ; 
                fs[s[l - 1] - 'a']-- ; 
                if (fs == fp) {
                    ans.push_back(l) ;
                }
            }
            return ans ; 
        }
    }
};

// fs[2] = fs['c'] = f['c' - 'a']

// 0 1 2 3 4 5 .... 25
// a b c d e f .... z
//97 98 99 100 101

// 97 - 97 = 0
// 98 - 97 = 1 
// 99 - 97 = 2 

/*
s = "cbaebabacd", p = "abc" m = p.length()
  m = 3
  l = r - (m - 1) ;
  l r       
 0123456789
 cbaebabacd

hahshing : F(x) => ASCII(x) - ASCII('a') ;
 a b c d e f g h i j k  l  m  n o p q r s t u v w x y z
 0 1 2 3 4 5 6 7 8 9 10 11 12 13
 0 0 0 0 0 0 0 0 0 0 0  0  0  0 0 0 0 0 0 0 0 0 0 0 0 0 
 
 a->0
 b->1
 c->2
*/















