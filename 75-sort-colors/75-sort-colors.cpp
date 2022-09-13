class Solution {
public:
    void sortColors(vector<int>& a) {
        int pointer = 0 ; 
        for (int i = 0 , n = a.size() ; i < n ; i++) {
            if (a[i] == 0) {
                swap(a[i] , a[pointer++]) ;
            }
        }
        for (int i = 0 , n = a.size() ; i < n ; i++) {
            if (a[i] == 1) {
                swap(a[i] , a[pointer++]) ;
            }
        }
    }
};
