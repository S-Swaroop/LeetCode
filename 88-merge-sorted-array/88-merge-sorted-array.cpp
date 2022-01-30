class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = 0 , j = 0 , dump = m ;
        while (i < m + n && j < n) {
            if (i >= m && a[i] == 0) {
                swap(a[i] , b[j]) ;
                i++ ; j++ ; dump++ ; 
            } else if (a[i] <= b[j]) { // a[i] is in the right place 
                i++ ; 
            } else { // b[j] should be in a[i]'s place 
                swap(a[i] , b[j]) ;
                i++ ; 
                int temp = j ; 
                while (j + 1 < n && b[j] > b[j + 1]) {
                    swap(b[j] , b[j + 1]) ;
                    j++ ; 
                }
                j = temp ;
            }
        }
    }
};