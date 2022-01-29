class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size() ; //array size
        sort(strs.begin() , strs.end()) ; 
        int n = min(strs[0].length() , strs[m - 1].length()) ;
        string longest_common_prefix = "" ; 
        for(int i = 0 ; i < n ; i++) {
            if(strs[0][i] == strs[m - 1][i]) {
                longest_common_prefix += strs[0][i] ; 
            } else {
                break ; 
            }
        }
        return longest_common_prefix ; 
    }
};
