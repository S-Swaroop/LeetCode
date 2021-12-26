class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() ; 
        int min_len = INT_MAX ; 
        for(auto i : strs)  min_len = min(min_len , (int)i.length()) ; 
        string ans = "" ; 
        for(int i = 0 ; i < min_len ; i++){
            bool f = 1 ; 
            for(int j = 0 ; j < n ; j++){
                f &= strs[j][i] == strs[0][i] ; 
            }
            if(f)   ans += strs[0][i] ; 
            else    break ;
        }
        return ans ; 
    }
};