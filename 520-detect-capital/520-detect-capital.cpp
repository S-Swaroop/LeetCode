class Solution {
public:
    bool detectCapitalUse(string word) {
        int res = count(word) ; 
        if(res == word.length() || res == 0 || (res == 1 && isupper(word[0]))){
            return true ; 
        }else{
            return false ;
        }
    }
private:
    int count(string &word){
        int res = 0 ; 
        for(char c : word){
            res += isupper(c) ? 1 : 0 ; 
        }
        return res ; 
    }
};