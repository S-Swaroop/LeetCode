class Solution {
public:
    string removeKdigits(string num, int k) {
        while (k > 0) {
            int i = 0 ; 
            int n = num.length() ;
            while (i + 1 < n && num[i] <= num[i + 1]) i++ ;
            num.erase(i , 1) ;
            k-- ;
        }
        while (!num.empty() && num[0] == '0')   num.erase(0 , 1) ;
        return num == "" ? "0" : num ; 
    }
};