class Solution {
public:
    int myAtoi(string s) {
        int n = s.length() ; 
        long long num = 0 ; 
        int strt = -1 ; 
        for(int i = 0 ; i < n ; i++){
            if(isdigit(s[i])){
                strt = i ; 
                break ; 
            }
        }
        if(strt == -1){
            return 0 ; 
        }
        for(int i = strt - 2 ; i >= 0 ; i--){
            if(s[i] != ' ') return 0 ; 
        }
        char sign = strt == 0 ? '+' : s[strt - 1] ;
        if(sign != '+' && sign != '-' && sign != ' ')   return 0 ; 
        for(int i = strt ; i < n ; i++){
            if(isdigit(s[i])){
                num = min((1ll << 31) , num * 10 + (s[i] - '0')) ;
            }else{
                break ; 
            }
        }
        if(sign == '-') num = max(-1 * (1ll << 31) , -1 * num) ;
        else    num = min(num , (1ll << 31) - 1) ;
        return num ; 
    }
};