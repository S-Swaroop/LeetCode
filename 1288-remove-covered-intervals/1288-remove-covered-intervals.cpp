class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        sort(intervals.begin() , intervals.end() , [&](vector<int> &a , vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1] ;
            } else {
                return a[0] < b[0] ; 
            }
        });
        auto covers = [&](int i , int j) {
            return (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) ;
        }; 
        int count = 0 , i = 0 ;
        while (i < n) {
            int j = i + 1 ; 
            while (j < n && (covers(i , j))) {
                count++ ;
                j++ ;     
            }
            i = j ; 
        }
        return n - count ;
    }
};