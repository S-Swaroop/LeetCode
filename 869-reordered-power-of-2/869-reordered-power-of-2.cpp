class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> ncount = count(n) ; 
        for (int i = 0 ; i < 32 ; i++) {
            if (ncount == count((1ll << i))) {
                return true ;
            }
        }
        return false ;
    }
private: 
    vector<int> count (int n) {
        vector<int> f(10 , 0) ;
        while (n > 0) {
            f[n % 10]++ ;
            n /= 10 ;
        }
        return f ;
    }
};