class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ; 
        sort(intervals.begin() , intervals.end()) ;
        int l = intervals[0][0] , r = intervals[0][1] ;
        for (int i = 1 , n = intervals.size() ; i < n ; i++) {
            if (intervals[i][0] <= r) {
                r = max(intervals[i][1] , r) ;
            } else {
                ans.push_back({l , r}) ; 
                l = intervals[i][0] , r = intervals[i][1] ; 
            }
        }
        if (ans.empty() || ans.back()[1] != r)
            ans.push_back({l , r}) ; 
        return ans ; 
    }
};