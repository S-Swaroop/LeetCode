class Solution {
public:
    int numDecodings(string s) {
        memset(memo , -1 , sizeof(memo)) ;
        return dp (0 , s) ;
    }
private: 
    int memo[101] ;
    int dp (int index , string s) {
        if (index >= s.length()) {
            return 1 ;
        } else if (memo[index] != -1) {
            return memo[index] ;
        } else {
            int &res = memo[index] ;
            res = 0 ;
            if (s[index] >= '1' && s[index] <= '9') {
                res += dp (index + 1 , s) ;
            }
            if (index < s.length() - 1) {
                int x = num(s[index] , s[index + 1]) ; 
                if (x >= 10 && x <= 26) {
                    res += dp (index + 2 , s) ;
                }
            }
            return res ;
        }
    }
    int num (char a , char b) {
        return ((a - '0') * 10) + (b - '0') ;
    }
};