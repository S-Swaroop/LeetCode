class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin() , a.end()) ; 
        vector<vector<int>> ans ; 
        ans.push_back(a[0]) ; 
        int n = a.size() ; 
        for(int i = 1 ; i < n ; i++){
            if(a[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , a[i][1]) ; 
            }else{
                ans.push_back(a[i]) ; 
            }
        }
        return ans ; 
    }
};