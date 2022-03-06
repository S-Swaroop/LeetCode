class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> f(102 , vector<double> (102 , 0.0)) ;
        f[0][0] = (double)poured ; 
        for (int r = 0 ; r < query_row ; r++) {
            for (int c = 0 ; c <= r ; c++) {
                double q = (f[r][c] - 1.0) / 2.0 ; 
                if (q > 0) {
                    f[r + 1][c] += q ; 
                    f[r + 1][c + 1] += q ; 
                }
            }
        }
        return min(1.0 , f[query_row][query_glass]) ;
    }
};