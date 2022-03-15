class Solution {
public:
    int numSplits(string s) {
        map<char , int> left , right ; 
        for (char &i : s) {
            right[i]++ ;
        }
        int ans = 0 ; 
        for (char &i : s) {
            if (right.find(i) != right.end()) {
                right[i]-- ;
                if (right[i] == 0) {
                    right.erase(i) ;
                }
            }
            left[i]++ ;
            if (left.size() == right.size()) {
                ans++ ;
            }
        }
        return ans ; 
    }
};