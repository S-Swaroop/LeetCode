class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> f(26 , 0) ;
        for (char &i : magazine) {
            f[i - 'a']++ ;
        }
        for (char &i : ransomNote) {
            f[i - 'a']-- ; 
            if (f[i - 'a'] < 0) {
                return false ;
            }
        }
        return true ;
    }
};