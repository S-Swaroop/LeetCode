class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOcc(26 , 0) ;
        int n = s.length() ;
        for(int i = 0 ; i < n ; i++){
            lastOcc[s[i] - 'a'] = i ; 
        }
        int f = 0 ; 
        vector<int> ans ;  
        int lst = 0 ; 
        for(int i = 0 ; i < n ; i++){
            f = max(f , lastOcc[s[i] - 'a']) ;
            if(i == f){
                ans.push_back(i - lst + 1) ; 
                lst = i + 1 ; 
            }
        }
        return ans ; 
    }
};