/*
 * Smart Recursion
*/

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


/*
 * Bitmasking/exhaustive search method
*/

// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         int n = arr.size() ;
//         int lim = 1 << n ; // this is our limit 
//         int max_length = 0 ; 
//         // running through all masks from 1 to 2^n - 1
//         for (int mask = 1 ; mask < lim ; mask++) { 
//             int length = 0 ;
//             bool unique = true ;
//             vector<int> f(26 , 0) ; 
//             for (int i = 0 ; i < n && unique ; i++) {
//                 if (mask & (1 << i)) { // checking whether this element is present in mask
//                     for (char &j : arr[i]) {
//                         f[j - 'a']++ ;
//                         if (f[j - 'a'] > 1) {
//                             unique = false ; 
//                             break ;
//                         }
//                         length++ ;
//                     }
//                 }
//                 if (!unique) {
//                     break ;
//                 }
//             }
//             if (unique) {
//                 max_length = max(max_length , length) ;
//             }
//         }
//         return max_length ;
//     }
// };