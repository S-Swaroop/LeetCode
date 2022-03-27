class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int , int>> s ; 
        for (int i = 0 , n = mat.size() ; i < n ; i++) {
            int sum = 0 ;
            for (int j = 0 ; j < mat[0].size() ; j++) {
                sum += mat[i][j] ;
            }
            s.insert({sum , i}) ;
            if (s.size() == k + 1) {
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