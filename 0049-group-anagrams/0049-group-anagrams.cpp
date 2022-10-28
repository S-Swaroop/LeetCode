class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string>> f ; 
        vector<int> freq(26 , 0) ;
        for (string &s : strs) {
            for (char &i : s) {
                freq[i - 'a']++ ;
            }
            f[freq].push_back(s) ; 
            fill(freq.begin() , freq.end() , 0) ; 
        }
        vector<vector<string>> ans ; 
        for (auto &i : f) {
            ans.push_back(i.second) ;
        }
        return ans ;
    }
};