class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto count = [&](int row) {
            if (mat[row][0] == 0)  return 0 ;
            int l = -1 , r = mat[row].size() ;
            while (r - l > 1) {
                int m = l + (r - l) / 2 ;
                if (mat[row][m]) {
                    l = m ; 
                } else {
                    r = m ;
                }
            }
            return r + 1 ;
        }; 
        set<pair<int , int>> s ; 
        for (int i = 0 , n = mat.size() ; i < n ; i++) {
            s.insert({count(i) , i}) ;
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
};