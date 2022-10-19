class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> f ; 
        for (string &i : words) {
            f[i]++ ;
        }
        vector<string> ans ; 
        for (auto &[word , _] : f) {
            ans.push_back(word) ;
        }
        sort(ans.begin() , ans.end() , [&](string &a , string &b) {
            if (f[a] == f[b]) {
                return a < b ;
            } else {
                return f[a] > f[b] ;
            }
        }) ;
        ans.resize(k) ; 
        return ans ;
    }
};