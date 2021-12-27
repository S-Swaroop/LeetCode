class Solution {
public:
    int findComplement(int num) {
        int res = 0 ; 
        int lim = log2(num) ;
        for(int i = 0 ; i <= lim ; i++){
            if(!(num & (1 << i))){
                res += (1 << i) ;
            }
        }
        return res ; 
    }
};