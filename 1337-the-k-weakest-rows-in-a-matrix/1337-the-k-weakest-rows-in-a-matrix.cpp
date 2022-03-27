class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int , int>> s ; 
        for (int i = 0 , n = mat.size() ; i < n ; i++) {
            s.insert({count(mat[i]) , i}) ;
            if (s.size() > k) {
                s.erase(--s.end()) ;
            }
        }
        vector<int> ans ;
        for (auto [sum , index] : s) {
            ans.push_back(index) ;
        }
        return ans ;
    }
private: 
    int count (vector<int> &a) {
        if (a[0] == 0)  return 0 ;
        int l = -1 , r = a.size() ;
        while (r - l > 1) {
            int m = l + (r - l) / 2 ;
            if (a[m]) {
                l = m ; 
            } else {
                r = m ;
            }
        }
        return r + 1 ;
    }
};