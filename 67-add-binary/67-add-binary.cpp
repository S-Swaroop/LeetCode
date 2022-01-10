class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0 ; 
        while(a.length() < b.length()){
            a = "0" + a ; 
        }
        while(a.length() > b.length()){
            b = "0" + b ; 
        }
        int n = a.length() ; 
        string s = "" ;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(a[i] == b[i]){
                if(a[i] == '1'){
                    s += '0' + carry ; 
                    carry = 1 ; 
                }else{
                    s += '0' + carry ; 
                    carry = 0 ; 
                }
            }else{
                if(carry){
                    s += '0' ; 
                    carry = 1 ; 
                }else{
                    s += '1' ; 
                    carry = 0 ; 
                }
            }
        }
        if(carry){
            s += '1' ; 
        }
        reverse(s.begin() , s.end()) ;
        return s ;
    }
};