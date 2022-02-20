class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        int count = 0 ; 
        for (auto &i : intervals) {
            for (auto &j : intervals) {
                if (i == j) continue ;
                if (j[0] <= i[0] && j[1] >= i[1]) {
                    // cout << i[0] << " " << i[1] << endl ;
                    count++ ; 
                    break ;
                }
            }
        }
        return n - count ;
    }
};