class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size() ;
        int lim = 1 << n ; 
        int max_length = 0 ; 
        for (int mask = 1 ; mask < lim ; mask++) {
            int length = 0 ;
            vector<int> f(26 , 0) ; 
            for (int i = 0 ; i < n ; i++) {
                if (mask & (1 << i)) {
                    for (char &j : arr[i]) {
                        f[j - 'a']++ ;
                        length++ ;
                    }
                }
            }
            bool unique = true ;
            for (int i = 0 ; i < 26 ; i++) {
                unique &= (f[i] < 2) ;
            }
            if (unique) {
                max_length = max(max_length , length) ;
            }
        }
        return max_length ;
    }
};