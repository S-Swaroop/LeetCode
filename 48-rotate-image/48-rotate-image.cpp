class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix) ;
        reverse(matrix) ;
    }
private: 
    void transpose (vector<vector<int>> &matrix) {
        for (int i = 0 , n = matrix.size() ; i < n ; i++) {
            for (int j = 0 ; j <= i ; j++) {
                swap(matrix[i][j] , matrix[j][i]) ;
            }
        }
    }
    void reverse (vector<vector<int>> &matrix) {
        for (vector<int> &a : matrix) {
            for (int i = 0 , n = a.size() ; i < n / 2 ; i++) {
                swap(a[i] , a[n - i - 1]) ;
            }
        }
    }
};