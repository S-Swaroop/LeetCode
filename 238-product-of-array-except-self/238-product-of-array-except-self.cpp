class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size() ; 
        vector<int> pref(n + 1 , 1) , suff(n + 1 , 1) , ans(n , 0) ; 
        for (int i = 0 ; i < n ; i++) {
            pref[i + 1] *= pref[i] * a[i] ;  
        }
        for (int i = n - 1 ; i > 0 ; i--) {
            suff[i - 1] *= suff[i] * a[i] ; 
        }
        for (int i = 1 ; i < n - 1 ; i++) {
            ans[i] = pref[i] * suff[i] ; 
        }
        ans[0] = suff[0] ;
        ans[n - 1] = pref[n - 1] ; 
        return ans ; 
    }
};