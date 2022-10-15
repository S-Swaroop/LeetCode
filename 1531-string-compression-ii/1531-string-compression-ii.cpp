// class Solution {
// public:
//     int getLengthOfOptimalCompression(string s, int k) {
//         this->s = s ;
//         memset(memo , -1 , sizeof(memo)) ;
//         return dp(0 , 26 , 0 , k) ;
//     }
// private: 
//     string s ;
//     int memo[101][27][101][101] ;
//     int dp (int index , int prev , int length , int k) {
//         if (k < 0) { // invalid
//             return INT_MAX ;
//         } 
//         if (index >= (int)s.size()) { // end of string
//             return 0 ;
//         } 
//         if (memo[index][prev][length][k] != -1) {
//             return memo[index][prev][length][k] ;
//         } else {
//             int &res = memo[index][prev][length][k] ;
//             res = INT_MAX ;
//             // remove current character
//             res = min(res , dp(index + 1 , prev , length , k - 1)) ;
//             // don't remove current character
//             if ((int)(s[index] - 'a') == prev) {
//                 int count = 0 ;
//                 if (length == 9 || length == 99 || length == 1) { // the cases when length of encrypted string increases
//                     count++ ;
//                 }
//                 res = min(res , dp(index + 1 , prev , length + 1 , k) + count) ;
//             } else {
//                 res = min(res , dp(index + 1 , (int)(s[index] - 'a') , 1 , k) + 1) ;
//             }
//             return res ;            
//         }
//     }
// };

int dp[101][27][101][101];
class Solution {
public:
    string str;
    int n;
    int minLength(int i, int prev, int len, int k)
    {
        if(k<0)    return INT_MAX;
        if(i>=n)    return 0;
        if(dp[i][prev][len][k] != -1)   return dp[i][prev][len][k];
        int ifDelete = minLength(i+1,prev,len,k-1);
        int keep = 0;
        if(str[i]-'a' == prev)
        {
            if(len==1 || len==9 || len==99)     keep++;
            keep += minLength(i+1, prev, len+1, k);
        }
        else    keep = 1 + minLength(i+1, str[i]-'a', 1, k);
        return dp[i][prev][len][k] = min(ifDelete, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return minLength(0,26,0,k);
    }
};