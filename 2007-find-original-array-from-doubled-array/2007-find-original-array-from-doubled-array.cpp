class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int m = changed.size() ; 
        if (m & 1) {
            return {} ;
        }
        int n = m / 2 ; 
        vector<int> original ;
        multiset<int> s(changed.begin() , changed.end()) ;
        for (int i = 0 ; i < n && !s.empty() ; i++) {
            original.push_back(*s.begin()) ; 
            s.erase(s.begin()) ;
            auto it = s.find(2 * original.back()) ;
            if (it == s.end() || *it != (original.back() * 2)) {
                return {} ;
            } else {
                s.erase(it) ;
            }
        }
        return original ;
    }
};