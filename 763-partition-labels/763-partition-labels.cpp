class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26 , -1) ; 
        for (int i = 0 , n = s.length() ; i < n ; i++) {
            last[s[i] - 'a'] = max(last[s[i] - 'a'] , i) ; 
        }
        vector<int> ans ; 
        for (int i = 0 , n = s.length() ; i < n ; ) {
            int j , end = last[s[i] - 'a'] ;
            for (j = i ; j <= end ; j++) {
                end = max(end , last[s[j] - 'a']) ;
            }
            ans.push_back(j - i) ; 
            i = j ; 
        }
        return ans ; 
    }
};