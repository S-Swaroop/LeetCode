class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans ;
        for (int i = 1 ; i <= 9 ; i++) {
            generate(i , n - 1 , k , ans) ;
        }
        return ans ;
    }
private: 
    void generate (int number , int n , int k, vector<int> &ans) {
        if (n == 0) {
            ans.push_back(number) ;
        } else {
            int last_digit = number % 10 ;
            if (last_digit + k <= 9) {
                number = (number * 10) + (last_digit + k) ;
                generate(number , n - 1 , k , ans) ;
                number /= 10 ;
            }
            if (k != 0 && last_digit - k >= 0) {
                number = (number * 10) + (last_digit - k) ;
                generate(number , n - 1 , k , ans) ;
                number /= 10 ;
            }
        }
    }
};