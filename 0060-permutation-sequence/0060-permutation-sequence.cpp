class Solution {
public:
    string getPermutation(int n, int k) {
        return next(n , k , digits.substr(0 , n)) ;
    }
private: 
    string digits = "123456789" ;
    int fact[10] = {1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880} ;
    string next (int n , int k , string left) {
        if (n == 1) {
            return left ;
        } else {
            int index = (k / fact[n - 1]) - (k % fact[n - 1] == 0) ;
            char c = left[index] ;
            left.erase(index , 1) ;
            return c + next(n - 1 , k - (index * fact[n - 1]) , left) ;
        }
    }
};