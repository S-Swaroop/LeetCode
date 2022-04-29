class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows) ; 
        for (int i = 0 ; i < numRows ; i++) {
            a[i].push_back(1) ;
        }
        for (int row = 1 ; row < numRows ; row++) {
            for (int j = 0 , n = a[row - 1].size() ; j + 1 < n ; j++) {
                a[row].push_back(a[row - 1][j] + a[row - 1][j + 1]) ;
            }
            a[row].push_back(1) ;
        }
        return a ;
    }
};