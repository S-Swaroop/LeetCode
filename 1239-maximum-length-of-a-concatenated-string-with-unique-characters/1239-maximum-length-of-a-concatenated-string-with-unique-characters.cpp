class Solution {
public:
    int maxLength(vector<string>& arr) {
        return helper(0 , 0 , arr) ;
    }
private: 
    int helper (int index , int mask , vector<string> &arr) {
        if (index >= (int)arr.size()) {
            return 0 ;
        } else {
            int t = mask ;
            bool possible = true ; 
            for (char &i : arr[index]) {
                if (t & (1 << (i - 'a'))) { // if true then this character is already present in the mask
                    possible = false ;
                    break ;
                }
                t |= (1 << (i - 'a')) ;
            }
            if (!possible) {
                return helper (index + 1 , mask , arr) ;
            } else {
                return max(helper(index + 1 , mask , arr) , (int)arr[index].length() + helper(index + 1 , t , arr)) ;
            }
        }
    }
};